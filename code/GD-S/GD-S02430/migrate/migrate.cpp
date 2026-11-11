//INVINCIBLE!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mn=1e6+5,in=4e18;
ll c,t,n,d,a[mn],dl[mn],dr[mn],ld[mn],rd[mn],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		a[0]=-in;
		a[n+1]=in;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}ll p=1;
		for(ll i=1;i<=n;i++){
			while(a[i]-a[p]>d)p++;
			ld[i]=p;
		}ld[n+1]=n+1;
		p=n;
		for(ll i=n;i;i--){
			while(a[p]-a[i]>d)p--;
			rd[i]=p;
		}rd[0]=0;
		for(ll i=1;i<=n;i++){
			dl[i]=0;
			if(i<n&&ld[i+1]==ld[i])continue;
			dl[i]=dl[ld[i]]+ld[i+1]-ld[i];
			if(ld[i+1]>i)dl[i]--;
		}for(ll i=n;i;i--){
			dr[i]=0;
			if(i>1&&rd[i-1]==rd[i])continue;
			dr[i]=dr[rd[i]]+rd[i]-rd[i-1];
			if(rd[i-1]<i)dr[i]--;
		}
		for(ll i=2;i<n-1;i++){
			if(ld[i+1]==ld[i+2]||ld[i+1]>=i)continue;
			if(rd[i-1]==rd[i]||rd[i]<=i+1)continue;
			ll ls=ld[i+2]-ld[i+1],rs=rd[i]-rd[i-1];
			ans+=(ls+dl[ld[i+1]])*(rs+dr[rd[i]]);
		}cout<<ans<<'\n';
	}
	return 0;
}/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/
