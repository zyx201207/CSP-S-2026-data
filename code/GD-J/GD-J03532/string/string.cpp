#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		char a;
		int k;
		cin>>k>>a;
		for(int i=1;i<=k;i++)s+=a;
	}for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i])ans++;
	}cout<<ans;
	return 0;
}
