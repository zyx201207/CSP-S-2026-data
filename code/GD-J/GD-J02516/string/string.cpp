#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin >> n;
	while(n--){
		int m;
		char c;
		cin >> m >> c;
		while(m--) s+=c;
	}
	n=s.size();
	for(int i=0;i<n/2;i++) if(s[i]!=s[n-i-1]) ans++;
	cout << ans;
	return 0;
} 
