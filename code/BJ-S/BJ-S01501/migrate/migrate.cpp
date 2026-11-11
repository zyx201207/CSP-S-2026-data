#include<iostream>
#include<queue>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N],nxt[N],dp[N],dp2[N],h[N];
deque<int> q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int p=1;
        for(int i=1;i<=n;i++){
            while(a[p]-a[i]<=d && p<=n) p++;
            nxt[i]=p-1;
        }
        if(c>10){
            int ans=0;
            for(int i=1;i<=n;i++){
                int l=i+1,r=nxt[i],flag=0;
                while(r!=nxt[r] && l<=r){
                    if(l!=r){
                        ans+=nxt[r-1]-max(nxt[r-2],r);
                    }
                    if(nxt[r-1]==nxt[r]){
                        l=max(nxt[r-2],r)+1;
                        r=nxt[r];
                        flag=1;
                        break;
                    }
                    l=nxt[r-1]+1;
                    r=nxt[r];
                }
                if(flag){
                    while(r!=nxt[r] && l<=r){
                        l=nxt[r-1]+1;
                        r=nxt[r];
                        if(l<=r) ans+=r-l+1;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            while(!q.empty()) q.pop_back();
            for(int j=1;j<=n;j++){
                h[j]=0;
            }
            dp[i]=0;
            dp2[i]=1;
            h[0]=1;
            for(int j=i+1;j<=n;j++){
                dp[j]=1e18;
                dp2[j]=0;
            }
            q.push_back(i);
            for(int j=i+1;j<=n;j++){
                while(!q.empty() && a[j]-a[q.front()]>d){
                    h[dp[q.front()]]-=dp2[q.front()];
                    q.pop_front();
                }
                if(q.empty()) break;
                dp[j]=dp[q.front()]+1;
                dp2[j]=min(3ll,h[dp[q.front()]]);
                if(dp2[j]==2) ans++;
                while(!q.empty() && dp[q.back()]>dp[j]){
                    h[dp[q.back()]]-=dp2[q.back()];
                    q.pop_back();
                }
                q.push_back(j);
                h[dp[j]]+=dp2[j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
