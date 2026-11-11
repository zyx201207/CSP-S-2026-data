#include <bits/stdc++.h>
#define ll long long
using namespace std;//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const int N=5e5+10;
ll n,m,a[N],s[N],ans;
unordered_map<ll,int>mp;
bool check(ll x, ll I){
	if((I-x+1)*a[I]-(s[I]-s[x-1])<=m) return 1;
	else return 0;
}//精华 
ll bs(ll r){ --r;
	if(!r) return 0;
	ll l=1,mid,tmp=r+1;
	while(l!=r){
		mid=(l+r)>>1;
		if(check(mid,tmp)) r=mid;
		else l=mid+1;
	}return tmp-l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i], mp[a[i]]++;
	sort(a+1,a+n+1);//排序+贪心+二分 
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1] && i!=1) continue;//一样的不枚举 
		ans=max(ans,bs(i)+mp[a[i]]);
	}cout<<ans;
	return 0;
}
/*

*/
