#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char c=getchar();
    int f=1,x=0;
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=2e5+10;
int a[N];
bool cnt[40][N];
bool vis[N];
signed main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=31;j++){
            if((a[i]>>j)&1){
                cnt[j][i]=true;
            }
        }
    }
    bool flag=false;
    for(int i=31;i>=0;i--){
        {
            int sum=0;
            for(int j=1;j<=n;j++){
                if(!cnt[i][j]) continue;
                if(!flag||(vis[j]&&cnt[i][j])) sum++;
            }
            if(sum<m) continue;
            for(int j=1;j<=n;j++){
                if(!flag)
                {
                    if(cnt[i][j]) vis[j]=true;
                }
                else{
                    if(vis[j]&&!cnt[i][j]) vis[j]=false;
                }
            }
            flag=true;
        }
    }
    int ans=-1,s1=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){

            if(ans==-1) ans=a[i];
            else ans&=a[i];
            s1++;
            if(s1==m) break;

        }
    }
    cout<<ans;
    return 0;
}
