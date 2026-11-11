#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		m-=(i-1)*(a[i]-a[i-1]);
		if(m<0){
			cout<<i-1;return 0;
		}
	}cout<<n;
	return 0; 
}//Done!O(nlogn);
