#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N];
int dp[N];
int lnk[N];
int cnt[N][4];//1 - 0,1 - 1 - 0,1 - 1 - 1+ - ...,1 - 2+ - ...
int lms[N];
int q[N],head=0,tail=0;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        head=tail=0;
        for(int i=1;i<=n;i++){
            while(head!=tail && x[i]-x[q[tail]]>d) tail++;
            q[head++]=i;
            lms[i]=q[tail];
        }
        lms[n+1]=n+1;
        lms[n+2]=n+2;
        for(int i=1;i<=n;i++){
            lnk[i]=min(i,lms[i+1])-lms[i];
            if(lms[i]<min(i,lms[i+1])) lnk[i]+=lnk[lms[i]];

            cnt[i][0]=lms[i]==i?0:cnt[lms[i]][min(2ll,i-lms[i]-1)];

            if(lms[i+1]<i) cnt[i][1]=(lms[i+1]==lms[i]?lnk[lms[i]]:(lms[i]+1==lms[i+1])?cnt[lms[i]][3]:cnt[lms[i]][min(2ll,lms[i+1]-lms[i]-1)])+i-lms[i+1];
            else cnt[i][1]=cnt[i][0];

            if(lms[i+2]<i) cnt[i][2]=(lms[i+1]==lms[i]?((lms[i+2]==lms[i+1])?0:lnk[lms[i]]):((lms[i]+1==lms[i+1])?cnt[lms[i]][3]:cnt[lms[i]][min(2ll,lms[i+1]-lms[i]-1)]))+lms[i+2]-lms[i+1];
            else cnt[i][2]=cnt[i][1];

            if(lms[i+1]<i) cnt[i][3]=(lms[i]==lms[i+1])?0:((lms[i]+1==lms[i+1])?cnt[lms[i]][3]:cnt[lms[i]][min(2ll,lms[i+1]-lms[i-1]-1)]);
            else cnt[i][3]=cnt[i][0];
        }
        head=tail=0;
        for(int i=1;i<=n;i++){
            if(lms[i]<i) ans+=cnt[lms[i]][min(2ll,i-lms[i]-1)];
        }
        cout<<ans<<'\n';
    }
}
