#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],ans=1;
bool f[N][40],vis[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int j=1;
        long long x=a[i];
        while(x){
            f[i][j]=(x%2==1);
            x/=2;
            j++;
        }
    }
    for(int i=1;i<31;i++){
        ans=(ans<<1)+1;
    }
    for(int i=31;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(f[j][i]&&!vis[j])cnt++;
        if(cnt==m){
            for(int j=1;j<=n;j++){
                if(f[j][i]&&!vis[j]){
                    ans=a[j];
                    break;
                }
            }
            for(int j=1;j<=n;j++){
                if(f[j][i]&&!vis[j]){
                    ans=ans&a[j];
                }
            }
            cout<<ans<<'\n';
            return 0;
        }
        if(cnt>m){
            for(int j=1;j<=n;j++){
                if(!f[j][i])vis[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans=a[i];
            break;
        }
    }
    int cc=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans=ans&a[i];
            cc++;
        }
        if(cc==m)break;
    }
    cout<<ans<<'\n';
    return 0;
}