#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll L, a[N], sum, n;
char c[N];
void sub(ll& i, ll& j, ll x){
	a[i]-=x;
	a[j]-=x;
	if(a[i]==0) i++;
	if(a[j]==0) j--;
	sum-=2*x;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int cnt = 0, p;
	for(int i = 1;i <= n;i++)
		cin>>a[i]>>c[i];
	ll i = 1, j = n, ans= 0;
	while(i<j){
		ll minx = min(a[i], a[j]);
		if(c[i]!=c[j]){
			ans+=minx;
		}
		sub(i, j, minx);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
