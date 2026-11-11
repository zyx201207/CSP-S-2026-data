#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
#define inf (1000'000'000'000'000'000ll)
#define mkp make_pair
using namespace std;
int c,t;
int n,nxt[2000005];
ll d,x[2000005],cnt1[2000005],cnt21[2000005],cnt22[2000005],ans;
int cnt(ll l,ll r){
    return upper_bound(x+1,x+n+1,r)-lower_bound(x+1,x+n+1,l);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        ans=0;
        int p1=1,p2=1;
        while(p2+1<=n&&x[p2+1]-x[p1]<=d)p2++;
        nxt[p1]=p2;
        for(;p1<=n;p1++){
            while(p2+1<=n&&x[p2+1]-x[p1]<=d)p2++;
            nxt[p1]=p2;
        }
        // for(int i=1;i<=n;i++)cout<<x[i]<<"->"<<x[nxt[i]]<<"\n";
        cnt1[n]=cnt21[n]=cnt22[n]=0;
        for(int i=n-1;i>=1;i--){
            int j=nxt[i],k=nxt[j];
            cnt1[i]=cnt21[i]=cnt22[i]=0;
            // cout<<i<<":"<<j<<","<<k<<"\n";
            if(i==j)continue;
            if(i+1==j)cnt1[i]=k-j;
            else if(i+2==j)cnt1[i]=cnt(x[j-1]+d+1,x[k]),cnt21[i]=cnt(x[j]+1,x[j-1]+d);
            else cnt1[i]=cnt(x[j-1]+d+1,x[k]),cnt21[i]=cnt(x[j-2]+d+1,x[j-1]+d);
            // cout<<"seri I cnt1["<<i<<"]="<<cnt1[i]<<" cnt21["<<i<<"]="<<cnt21[i]<<" cnt22["<<i<<"]="<<cnt22[i]<<"\n";
            // if(x[k]-x[j-1]>d)cnt1[i]+=cnt1[j],cnt2[i]+=cnt2[j];
            // else if(x[k]-x[j-2]>d)cnt2[i]+=cnt1[j];
            if(x[k]-x[j-1]>d){
                cnt1[i]+=cnt1[j],cnt22[i]+=cnt22[j];
                if(x[k-1]-x[j-1]>d)cnt22[i]+=cnt21[j];
                // cout<<k<<" "<<x[k]<<" "<<j-1<<" "<<x[j-1]<<" ";
                // cout<<"sol1\n";
            }
            else if(x[k]-x[j-2]>d)cnt21[i]+=cnt1[j];//,cout<<"sol2\n";
            // cout<<"seri J cnt1["<<i<<"]="<<cnt1[i]<<" cnt21["<<i<<"]="<<cnt21[i]<<" cnt22["<<i<<"]="<<cnt22[i]<<"\n";
            ans+=cnt21[i]+cnt22[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}