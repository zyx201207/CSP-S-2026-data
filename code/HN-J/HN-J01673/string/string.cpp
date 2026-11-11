#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long cn;char c;scanf("%lld%c",&cn,&c);
		for(long long j=1;j<=cn;j++)s+=c;
	}
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-i-1])cnt++;
	cout<<cnt;
	return 0;
}
