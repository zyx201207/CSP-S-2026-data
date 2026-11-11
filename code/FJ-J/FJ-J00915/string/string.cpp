#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<(s.size())/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
