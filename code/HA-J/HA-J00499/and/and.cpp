#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005],ans,Max = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll num;
	for(int i = n;i > m;i --){
		num = a[i];
		for(int j = i-1;j >= i-m+1;j --){
			num &= a[j];
		}
		ans = max(ans,num);
	}
	cout<<ans;
	return 0;
}
