#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(int j=1;j<=t;j++) s+=c;
	}
	const int L=s.size();
	for(int i=0;2*i<L;i++){
		if(s[i]!=s[L-1-i]){
			ans++;
		} 
	}
	cout<<ans;
	return 0;
}
