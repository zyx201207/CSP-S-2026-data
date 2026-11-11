#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--)
			s+=c;
	}
	int ans=0;
	for(int i=0;i<s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
//		cout<<s[i]<<' '<<s[s.size()-i-1]<<'\n';
	}
	cout<<ans;
	return 0;
} 
