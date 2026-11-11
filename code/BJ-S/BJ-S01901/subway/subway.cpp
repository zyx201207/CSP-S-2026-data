#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10005];
int f[1005][1005];
int t[1005][1005];
struct node{
    int a,b;
}s[10006];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++){
        f[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int x,y;
        int s1,s2;
        cin>>x>>s1>>y>>s2;
       // cout<<x<<" "<<s1<<" "<<y<<" "<<s2<<endl;
        f[x][y]=f[y][x]=s1+s2;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
       //     cout<<f[i][j]<<" ";
        }
      //  cout<<endl;
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
