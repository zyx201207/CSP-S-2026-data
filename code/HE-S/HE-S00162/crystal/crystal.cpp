#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mix=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		m-=(a[i]-a[i-1])*(i-mix);
		while(m<0){
			m+=(a[i]-a[mix]);
			mix++;
		}
		ans=max(ans,i-mix+1);
	}
	cout<<ans;
	return 0;
}
