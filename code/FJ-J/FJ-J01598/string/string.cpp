#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])ans++;
	cout<<ans;
	return 0;
}
