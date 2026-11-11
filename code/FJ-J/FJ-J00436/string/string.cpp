#include<iostream>
#include<string>
#include<cstdio>
#define int long long 
using namespace std;
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,d=0,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		int a;char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++)s+=b;
	}
	int c1=0,c2=s.size()-1;
	for(int i=0;i<=s.size()/2;i++){
		//cout<<s[c1]<<' '<<s[c2]<<endl;
		if(s[c1]!=s[c2])ans++;
		c1++,c2--;
	}
	cout<<ans;
	return 0;
}
