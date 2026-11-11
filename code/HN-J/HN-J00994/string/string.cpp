#include <bits/stdc++.h>
#define int long long
using namespace std;
string s,b;
int a,ansa,ans;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}


