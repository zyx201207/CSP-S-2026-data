#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++) s+=a;
	}
	for(int i=0;i<s.size()/2+s.size()%2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
