#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	vector<char> b(n+1);
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	ll l=1,r=n,cnt=0;
	while(l<=r){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		int t=min(a[l],a[r]);
		if(b[l]!=b[r])cnt+=t;
		a[l]-=t,a[r]-=t;
	}
	cout<<cnt;
	return 0;
}
