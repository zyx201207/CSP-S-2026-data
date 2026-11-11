#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500007];
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll lft=1,rgh=1;
	ll cst=0,num=1;
	while(rgh<n){
		rgh++;
		cst+=(a[rgh]-a[rgh-1])*num;
		num++;
		while(cst>m){
			cst-=(a[rgh]-a[lft]);
			lft++;
			num--;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
