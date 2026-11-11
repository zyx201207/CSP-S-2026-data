#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll l=0,mm=0;
	for(int i=1; i<=n; i++){
		if(i==1){
			ans=1;
			continue;
		}
		mm+=(i-l-1)*(a[i]-a[i-1]);
		while(mm>m){
			mm-=a[i]-a[++l];
		}
		ans=max(ans,i-l);
	}
	cout << ans << '\n';
	return 0;
}
