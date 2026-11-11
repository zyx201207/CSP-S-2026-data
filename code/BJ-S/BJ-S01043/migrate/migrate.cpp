#include <iostream>
using namespace std;
#define MAXN 5005
int c,t,n,d,a[MAXN],lst[MAXN],fst[MAXN],spe[MAXN],ans=0;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        lst[0]=1;
        for(int i=1;i<=n;i++){
            lst[i]=lst[i-1];
            while(a[i]-a[lst[i]]>d) lst[i]++;
        }
        fst[n+1]=n;
        for(int i=n;i>=1;i--){
            fst[i]=fst[i+1];
            while(a[fst[i]]-a[i]>d) fst[i]--;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k=i,lfst=i,tot=0;
                while(k<j){
                    if(lst[fst[i]]<i) tot++;
                    if(tot>1) break;
                    lfst=k;
                    k=fst[k];
                }
                if(k>=j&&lst[j]<lfst&&lfst!=i&&tot==0){
                        ans++;
                }
                else if(k>=j&&lst[j]>=lfst&&tot==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
haofeijingaweishenmebushiqiayouyitiao(jishinayangyehenfeijing)fangqilewoyaodabaolizhiyuweishenmezhemedashiyinweiwomeizhaodaozhongyingwenshurufadeqiehuan
#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define MAXN 2000005
int a[MAXN],fst[MAXN],lst[MAXN],spe[MAXN],sum[MAXN],val[MAXN],c,t,n,d,ans;
vector<int> edg[MAXN];
signed main(){
    freopen("migrate1.in","r",stdin);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        lst[0]=1;
        for(int i=1;i<=n;i++){
            lst[i]=lst[i-1];
            while(a[i]-a[lst[i]]>d) lst[i]++;
        }
        fst[n+1]=n;
        for(int i=n;i>=1;i--){
            fst[i]=fst[i+1];
            while(a[fst[i]]-a[i]>d) fst[i]--;
        }
        for(int i=1;i<=n;i++){
            cout<<lst[i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<fst[i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            edg[fst[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(fst[i]!=i&&lst[i]!=i&&lst[fst[i]]<i) spe[lst[i]]=true;
            val[i]=lst[lst[fst[fst[i]]]]-i;
            if(val[i]<0) val[i]=0;
        }
        for(int i=1;i<=n;i++)
            cout<<val[i]<<' ';
        cout<<endl;
        for(int i=1;i<=n;i++){
            if(fst[i]==i) continue;
            int sm=0;
            for(int j=0,ed=edg[i].size();j<ed;j++){
                sm+=sum[j];
            }
            int v=fst[i]-fst[i-1];
            ans+=v*sm;
            if(spe[i]) sum[i]=val[i];
            else sum[i]=sm+val[i];
        }
        for(int i=1;i<=n;i++){
            if(fst[i]==i) continue;
            ans+=(fst[i]-i-1)*(fst[i]-i-2)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
