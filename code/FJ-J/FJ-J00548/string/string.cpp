#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,he,a,flag,ans;
char c;
string s;
signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=0;j<a;j++)s+=c;
	}
	he=s.size();
	for (int i=0;i<he/2;i++){
		if (s[i]!=s[he-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
