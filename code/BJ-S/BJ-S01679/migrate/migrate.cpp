#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int cc,t;
int n,d;
int r[2000005],l[2000005];
ll x[2000005],ans;
int f[2000005],g[2000005];
int se[2000005],sse[2000005];
vector<int>v[2000005],vv[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>cc>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int cur=1;
        for(int i=1;i<=n;i++){
            while(cur<n&&x[cur+1]<=x[i]+d)cur++;
            r[i]=cur;
        }
        cur=n;
        for(int i=n;i>0;i--){
            while(cur>1&&x[cur-1]>=x[i]-d)cur--;
            l[i]=cur;
        }
        for(int i=1;i<=n;i++)v[i].clear(),vv[i].clear();
        for(int i=1;i<=n;i++){
            if(l[i]<i)v[l[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(r[i]>i)vv[r[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)se[i]=0,sse[i]=v[i].size();
        for(int i=1;i<=n;i++){
            while(se[i]<vv[i].size()&&vv[i][se[i]]<l[i]+1)se[i]++;
            //int u=lower_bound(vv[i].begin(),vv[i].end(),l[i]+1)-vv[i].begin();
            int u=se[i];
            f[i]=1;
            if(vv[i].size())f[i]+=vv[i].size()-u;
            if(r[l[i]]==i&&l[i]!=i)f[i]+=f[l[i]];

        }
        for(int i=n;i>0;i--){
            while(sse[i]&&v[i][sse[i]-1]>=r[i])sse[i]--;
            //int u=lower_bound(v[i].begin(),v[i].end(),r[i])-v[i].begin();
            int u=sse[i];
            g[i]=1;
            if(v[i].size())g[i]+=u;
            if(l[r[i]]==i&&r[i]!=i)g[i]+=g[r[i]];

        }
        for(int i=1;i<=n;i++){
            if(r[i]<=i+1)continue;
            ans+=v[r[i]-1].size();
        }
        for(int i=2;i<=n;i++){
            if(l[i-1]!=i-1&&r[i]!=i&&r[l[i-1]]==i&&l[r[i]]==i-1){
                ans+=1ll*(f[l[i-1]]-1)*(g[r[i]]-1);
            }
        }
        for(int i=1;i<=n;i++){
            int R=r[r[i]];
            if(r[i]==l[R]+1){
                ans+=g[R]-1;
            }
        }
        for(int i=1;i<=n;i++){
            int L=l[l[i]];
            if(l[i]==r[L]-1){
                ans+=f[L]-1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
