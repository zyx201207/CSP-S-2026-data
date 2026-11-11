#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long ans,l;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=0;j<a;j++)s+=c; 
	}
	for(int i=0;i<ceil(l/2);i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
