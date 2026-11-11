#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
ll n,m,a[N],ch[N],sum[N],ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		ch[i]=a[i]-a[i+1];
	}
	for(int i=1;i<=n-1;i++){
		ch[i]+=ch[i-1];
	}
	for(int i=1;i<=n-1;i++){
		sum[i]=sum[i-1]+ch[i];
	}
	ll l=1,r=1;
	while(r<=n){
		ll needm=sum[r-1]-sum[l-1]-(ch[l-1]*(r-l));
		if(needm<=m){
			ans=max(ans,(r-l+1));
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
