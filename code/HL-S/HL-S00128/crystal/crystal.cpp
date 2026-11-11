#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m;
ll a[500010],diff[500010],sum,k,p,last,ans ;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		diff[i] = a[i]-a[i-1];
	}
	for(int i = 1;i <= n;i++){
		k = p*diff[i]+k;
		p++;
		while(k > m&&last <= i){
			k = k-(a[i]-a[last]);
			last++;
			p--;
		}
		ans = max(ans,p);
	}
	cout <<ans;
	return 0;
}