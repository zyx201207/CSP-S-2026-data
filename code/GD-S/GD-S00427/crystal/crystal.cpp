#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
const long long MAX = 9e18;
ll n,m;
ll a[maxn],b[maxn],pre[maxn],pre2[maxn];
bool check(int x){
	ll mn = MAX;
	for(int i = 1;i<=n-x+1;i++){
		int mid = a[i+x-1];
		ll num = mid*(x-1)-(pre[i+x-2]-pre[i-1]);
		mn = min(mn,num);
	}
	if(mn<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll mx = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		//if(a[i]>0){
			pre[i] = pre[i-1]+a[i];
			//pre2[i] = pre2[i-1];
		//}
		//else{
			//pre2[i] = pre2[i-1]+a[i];
			//pre[i] = pre[i-1];
		//}
	}
	int l = 0,r = n;
	int ans = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}
		else{
			r = mid-1;
		}
	}
	cout<<ans;
}
