#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=2e6+6;
int testid,T,n,d,a[N];
pii f[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>testid>>T;
    if(testid==11||testid==12){
        while(T--){
            cin>>n>>d;int ans=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            int dis=a[2]-a[1],cnt=d/dis;
            if(cnt<2)cout<<0<<'\n';
            else cout<<max(n-(2*cnt-1),0ll)<<'\n';
        }
        return 0;
    }
    if(testid==13||testid==14){
        while(T--){
            cin>>n>>d;int ans=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int st=1;st<=n;st++){
                int pos1=upper_bound(a+1,a+n+1,a[st]+d)-a-1;
                if(pos1==st||pos1==st+1||pos1==n)continue;
                if(a[pos1-2]+d>=a[n])continue;
                int qwq1=upper_bound(a+1,a+n+1,a[pos1-2]+d)-a;
                int qwq2=upper_bound(a+1,a+n+1,a[pos1-1]+d)-a-1;qwq2=min(qwq2,n);
                ans+=(qwq2-qwq1+1);
            }cout<<ans<<'\n';
        }
        return 0;
    }
    while(T--){
        cin>>n>>d;int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int st=1;st<=n;st++){
            f[st]={0,1};
            for(int i=st+1;i<=n;i++){
                int pos=lower_bound(a+1,a+n+1,a[i]-d)-a;
                if(pos<st)pos=st;if(pos==i)break;
                f[i].first=f[pos].first+1,f[i].second=f[pos].second;
                for(int j=pos+1;j<=min(pos+2,i-1);j++)
                    if(f[j].first==f[pos].first)f[i].second+=f[j].second;
                f[i].second=min(f[i].second,3ll);
                if(f[i].second==2)ans++;
            }
        }cout<<ans<<'\n';
    }
    return 0;
}