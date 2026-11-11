#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	//cout<<s<<" "<<s.length();
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i])ans++;
		//cout<<i<<" "<<s.length()-1-i<<endl;
		//cout<<s[i]<<" "<<s[s.length()-1-i]<<endl;
	}
	cout<<ans;
	return 0;
}
