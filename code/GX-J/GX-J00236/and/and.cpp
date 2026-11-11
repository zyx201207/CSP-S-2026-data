#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m; 
	vector<int> s(n);
	for (int i=0;i<n;i++) cin>>s[i];
	sort(s.rbegin(),s.rend());
	long long ans=s[0];
	for (int i=1;i<m;i++) ans=(ans & s[i]);
	cout<<ans;
	return 0;
}
