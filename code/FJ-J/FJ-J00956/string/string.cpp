#include <bits/stdc++.h>
using namespace std;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int sum;
		char c;
		cin>>sum>>c;
		while(sum--) s+=c;
	}
	int ans=0;
	for(int i=1;i<=s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i+1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
