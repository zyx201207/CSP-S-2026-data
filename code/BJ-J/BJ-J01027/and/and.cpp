#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
vector<int> p[40];
bool vis[N],vis2[N],vis3[N],flag=0;
void solve(){
    int res=0;
    for(int i=30;i>=1;i--){
        int len=p[i].size();
        if(len>=m){
            if(!flag){
                flag=1;
                for(auto j:p[i]) vis[j]=1;
                res+=(1<<(i-1));
            }else{
                int cnt=0;
                for(int j=1;j<=n;j++) vis3[j]=0;
                for(auto j:p[i]) vis3[j]=1;
                for(int j=1;j<=n;j++){
                    vis2[j]&=vis3[j];
                    cnt+=vis2[j];
                }
                if(cnt>=m){
                    for(int j=1;j<=n;j++) vis[j]=vis2[j];
                    res+=(1<<(i-1));
                }
            }
            for(int j=1;j<=n;j++) vis2[j]=vis[j];
        }
    }
    cout<<res<<"\n";
    return;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            if(a[i]&(1<<(j-1))) p[j].push_back(i);
        }
    }
    solve();
    return 0;
}