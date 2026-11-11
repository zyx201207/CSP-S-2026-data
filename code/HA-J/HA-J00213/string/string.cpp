#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1="",s2="";
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long num;
		char zf;
		cin>>num>>zf;
		for(int j=1;j<=num;j++)s1+=zf;
	}
	for(int i=s1.size()-1;i>=0;i--)s2+=s1[i];
	long long ans=0;
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s2[i])ans++;
	}
	cout<<ans;
	return 0;
}
