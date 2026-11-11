#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
int c,T,n;
ll a[maxn],d;
ll dis[maxn];
vector<int> e[maxn];
ll cnt[maxn];
queue<int> q;
int l[maxn],r[maxn];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        if(n<=5000){
            for(int i=1;i<=n;i++) e[i].clear(),cnt[i]=0;
            for(int i=1;i<=n;i++) cin>>a[i];
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[j]>a[i]+d) break;
                    e[i].push_back(j);
                }
            }
            ll ans=0;
            for(int s=1;s<=n;s++){
                for(int j=1;j<=n;j++) dis[j]=1e18;
                q.push(s);
                cnt[s]=1;
                dis[s]=0;
                while(!q.empty()){
                    int i=q.front();q.pop();
                    if(cnt[i]==2){
                        ans++;
                    }
                    for(int j:e[i]){
                        if(dis[j]>dis[i]+1){
                            cnt[j]=cnt[i];
                            dis[j]=dis[i]+1;
                            q.push(j);
                        }else if(dis[j]==dis[i]+1){
                            cnt[j]+=cnt[i];
                            if(cnt[j]>=3) cnt[j]=3;
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }else{
            ll ans=0;
            for(int i=0;i<=n+4;i++){
                l[i]=r[i]=0;
            }
            for(int i=2;i<=n+1;i++){
                cin>>a[i];
            }
            a[0]=-9e18;a[n+3]=9e18;
            a[1]=a[2]-d-1;
            a[n+2]=a[n+1]+d+1;
            for(int i=3;i<=n+1;i++){
                if(a[i-1]>=a[i]-d&&a[i-2]<a[i]-d&&a[i+1]>a[i-1]+d){
                    l[i]=l[i-1]+1;
                }
                //cout<<l[i]<<" ";
            }
            //cout<<'\n';
            for(int i=n;i>=2;i--){
                if(a[i+1]<=a[i]+d&&a[i+2]>a[i]+d&&a[i-1]<a[i+1]-d){
                    r[i]=r[i+1]+1;
                }
                //cout<<r[i]<<" ";
            }
            //cout<<'\n';
            //for(int i=1;i<=n+2;i++) cout<<a[i]<<" ";
            //cout<<'\n';
            for(int i=3;i<=n;i++){
                /*
                j->i->k
                j->i+1->k
                a[i-1]<a[k]-d<=a[i]<a[i+1]<=a[j]+d<a[i+2]
                */
                int RL=lower_bound(a,a+n+2,a[i-1]+d+1)-a;
                int RR=lower_bound(a,a+n+2,a[i]+d+1)-a-1;
                int LL=lower_bound(a,a+n+2,a[i+1]-d)-a;
                int LR=lower_bound(a,a+n+2,a[i+2]-d)-a-1;
                //cout<<LL<<" "<<LR<<" "<<i<<" "<<i+1<<" "<<RL<<" "<<RR<<'\n';
                RL=max(RL,i+2);
                LR=min(LR,i-1);
                if(LL>LR) continue;
                if(RL>RR) continue;
                ll cntl=LR-LL+1+l[LL],cntr=RR-RL+1+r[RR];
                ans+=cntl*cntr;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

