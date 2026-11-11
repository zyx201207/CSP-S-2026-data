#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,e[N],p[N]={0},q=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>e[i];
    sort(e+1,e+n+1);p[1]=e[1];
    for(ll i=2;i<=n;i++) p[i]=p[i-1]+(e[i]-e[i-1])*i;
    for(ll i=1;i<=n;i++){
		if(p[i]<=m){q=max(q,i+1);continue;}
        ll l=0,r=i-1;
        while(l<r){
            ll mid=(l+r)/2,e=p[i]-p[mid],y=e[i]-e[mid];
            if((e-(mid+1)*y)>m) l=mid+1;
            else r=mid;
        }
        q=max(q,i-l);
    }
    cout<<q<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*created by luve on 2026/10/31 15:34*/