#include<bits/stdc++.h>
using namespace std;
int n;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int ans=0;
	n=s.size();
	for(int i=0;i<n/2;i++){
//		cout<<s[i];
		if(s[i]!=s[n-i])ans++;
	}
	cout<<ans;
}
