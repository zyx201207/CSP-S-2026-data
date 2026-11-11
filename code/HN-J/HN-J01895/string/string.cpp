#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	for(long long i=0;i<s.size()/2;i++){
		long long to=s.size()-1-i;
		if(s[i]!=s[to]) ans++;
	}
	cout<<ans;
	return 0;
}

