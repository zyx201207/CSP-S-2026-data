#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a=0;cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		char c;int x;cin>>x>>c;
		if(x>=1e9){cout<<(n/2)*x;return 0;}
		a+=x;
		for(int j=1;j<=x;j++)s+=c;
	}n=0;
	for(int i=0;i<=(a/2);i++){
		int k=a-i-1;
		if(s[i]==s[k])continue;
		else n++;
	}cout<<n;
	return 0;
}
