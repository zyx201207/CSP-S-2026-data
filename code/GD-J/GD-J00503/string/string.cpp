#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int ans=0;
	for(int i=0;i<s.size()/2;i++) if(s[s.size()-i-1]!=s[i]) ans++;
	cout<<ans;
	return 0;
}
