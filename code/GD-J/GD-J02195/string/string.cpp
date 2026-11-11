#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=1;i<=(s.size()/2);i++){
		if(s[i]!=s[s.size()-i])ans++;
	}
	cout<<ans;
}
