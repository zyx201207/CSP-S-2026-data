#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=500007;

ll arr[MAXN],pref[MAXN],n,m,res=1;
ll query(ll l,ll r){
	return pref[r]-pref[l-1];
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>arr[i];
	sort(arr,arr+n);
	for(ll i=1;i<=n;++i)pref[i]=arr[i]+pref[i-1];
	
	for(ll l=1,r=1,tmp;r<=n;++r){
		tmp=arr[r]*(r-l+1)-query(l,r);
		while(tmp>m){
			++l;
			tmp=arr[r]*(r-l+1)-query(l,r);
		}
		res=max(res,r-l+1);
	}
	cout<<res<<endl;
	return 0;
}
