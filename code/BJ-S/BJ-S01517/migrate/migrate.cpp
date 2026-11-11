#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,d,a[2000005];
ll len[2000005],tag[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        ll nowans=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++)cin>>a[i];
        for(ll i=1;i<n;i++){
            for(ll j=i;j<=n;j++){
                for(ll k=1;k<=n;k++)len[k]=1e18,tag[k]=0;
                len[i]=0;
                ll nowpos=i,maxn=1e18;
                while(nowpos!=j){
                    ll pos=upper_bound(a+1,a+j+1,a[nowpos]+d)-a-1;
                    maxn=min(maxn,pos-nowpos);
                    if(pos==nowpos)break;
                    len[pos]=len[nowpos]+1;
                    nowpos=pos;
                }
                ll r=nowpos;
                for(ll k=r-1;k>=i;k--){
                    if(len[k+1]>len[k])continue;
                    len[k]=len[k+1];
                }
                for(ll k=i;k<=r;k++){
                    tag[k]+=tag[k-1];
                    ll nxt=upper_bound(len+1,len+j+1,len[k])-len;
                    ll pos=upper_bound(a+1,a+j+1,a[k]+d)-a-1;
                    if(nxt<=pos)tag[nxt]++,tag[pos+1]--;
                }
                nowans+=(tag[j]==2);
            }
        }
        cout<<nowans<<endl;
    }
    return 0;
}
