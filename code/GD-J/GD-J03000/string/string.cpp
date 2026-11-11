#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	int a[n+1];
	char c[n+2];
	for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
	
	string s;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	ll l=0;
	for (int i=1;i<=n;i++) l+=a[i];
	double mid=(1.0*l)/2;
	ll ans=0;
	for (int i=0;i<mid;i++){
		if (s[i]!=s[l-i-1]) ans++;
	}
	
	cout<<ans;
	return 0;
}
