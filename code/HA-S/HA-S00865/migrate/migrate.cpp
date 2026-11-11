#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2e6+114;
int lf[N],rt[N];
int llk[N],rlk[N];
ll pos[N],lsm[N],rsm[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll dis;
		cin>>n>>dis;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
			lf[i]=rt[i]=0;
			llk[i]=rlk[i]=0;
			lsm[i]=rsm[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(i==1 or pos[i-1]<pos[i]-dis){
				lf[i]=0;
			}
			else{
				lf[i]=lower_bound(pos+1,pos+n+1,pos[i]-dis)-pos;
			}
			if(i==n or pos[i+1]>pos[i]+dis){
				rt[i]=0;
			}
			else{
				rt[i]=upper_bound(pos+1,pos+n+1,pos[i]+dis)-pos-1; 
			}
		}
		for(int i=1;i<=n;i++){
			if(lf[i])rlk[lf[i]]++;
			if(rt[i])llk[rt[i]]++;
		}
		for(int i=1;i<=n;i++){
			lsm[i]=llk[i];
			if(lf[i]!=0 and rt[lf[i]]==i){
				lsm[i]+=lsm[lf[i]];
			}
		}
		for(int i=n;i>=1;i--){
			rsm[i]=rlk[i];
			if(rt[i]!=0 and lf[rt[i]]==i){
				rsm[i]+=rsm[rt[i]];
			}
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			if(rt[i]==i+1 or lf[i+1]==i)continue;
			if(rt[i]==0 or lf[i+1]==0)continue;
			ll l,r;
			l=llk[i+1],r=rlk[i];
			if(lf[i+1]==lf[i] and rt[lf[i]]==i+1){
				l+=lsm[lf[i]];
			}
			if(rt[i]==rt[i+1] and lf[rt[i]]==i){
				r+=rsm[rt[i]];
			}
			ans+=l*r;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956


0 1
10 29
-100 -71 -42 -23 -14 -4 14 42 71 99
*/
