#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,inf=0x3f3f3f3f;
ll c,t,d,n,m,ans=0,sum=0;
ll a[N],s[N][N],f[N][N];
void find(int x){
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d)f[x][i]=s[x][i]=1;
    }
}
void dfs(int x,int tx,int y,int e){
    if(tx==y){
        if(e==s[x][y]){
            sum++;
            return;
        }
    }
    for(int i=tx+1;i<=y;i++){
        if(a[i]-a[tx]<=d){
            dfs(x,i,y,e+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        memset(f,0,sizeof(0));
        memset(s,inf,sizeof(s));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)find(i);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(s[i][k]+s[k][j]<s[i][j])s[i][j]=s[i][k]+s[k][j];
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i][j]!=1){
                    sum=0;
                    dfs(i,i,j,0);
                    f[i][j]=sum;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(f[i][j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
