#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int mm;
		cin>>mm;
		char a;
		cin>>a;
		for(int k=1;k<=mm;k++){
			s+=a;
		}
	}
	for(int i=0;i<(s.size()>>1);i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
