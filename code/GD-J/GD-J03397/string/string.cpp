#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
string s="0";
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1])ans++;
	}
	cout<<ans;
	return 0;
}

