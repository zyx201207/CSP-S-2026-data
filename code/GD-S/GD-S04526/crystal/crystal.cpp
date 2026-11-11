#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5e5+5;
ll a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("test.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;cin>>n>>m;
	bool all_ai=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>2 and a[i]-a[i-1]!=a[i-1]-a[i-2]) all_ai=0;
	}
	if(all_ai){
		int ans=1;
		ll tmp=m;
		for(int i=n-1;i>=1;i--){
			if(tmp>=a[n]-a[i]){
				tmp-=(a[n]-a[i]);
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		if(ans>i)break;
		int res=1;
		ll tmp=m;
		for(int j=i-1;j>=1;j--){
			if(tmp>=a[i]-a[j]){
				tmp-=(a[i]-a[j]);
				res++;
			}
			else break;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
