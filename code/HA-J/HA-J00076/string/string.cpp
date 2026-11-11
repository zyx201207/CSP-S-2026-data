#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)s+=c;
	}
	reverse(s1.begin(),s1.end());
	for(long long i=0;i<s.size();i++){
		cout<<s1[i]<<" ";
		if(s[i]!=s1[i])ans++;
	}
	cout<<ans;
	
	return 0;
}
