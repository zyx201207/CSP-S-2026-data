#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
string s;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int l=s.size();
	for(int i=1;i<=l/2;i++) if(s[i-1]!=s[l-i]) ans++;
	cout<<ans;
	return 0;
}
