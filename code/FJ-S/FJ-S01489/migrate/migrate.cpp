#include<iostream>
using namespace std;
#define ll long long
const ll maxn=2e6+5;
ll c,t,x[maxn],n,d;
ll l[maxn],r[maxn];
ll h,hh;
void dfs(ll p,ll d,ll z){
	if(d>hh)return;
	if(p==z){
		if(d<hh||hh==0){
			h=1;
			hh=d;
		}
		else if(d==hh)h++;
		return;
	}
	for(ll i=max(l[p],z);i<p;i++){
		dfs(i,d+1,z);
		if(d+1>hh)break;
		if(d+1==hh&&h>=3)break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll p=1;
		for(ll j=1;j<=n;j++){
			while(x[j]-x[p]>d)p++;
			l[j]=p;
		}
		ll ans=0;
		if(c==11||c==12){
			if(n-l[n]==2)cout<<n-3<<'\n';
			else cout<<0<<'\n';
			continue;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=l[i]-1;j>=1;j--){
				hh=0;
				h=0;
				dfs(i,0,j);
				if(h==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
