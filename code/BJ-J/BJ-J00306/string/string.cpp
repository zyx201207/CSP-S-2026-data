#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a;
char c;
string s;
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s=s+c;
	}
	int l=s.length();
	int ans=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}