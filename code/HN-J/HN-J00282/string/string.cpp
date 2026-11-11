#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,minx=0;
	string s="",b;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		for(int j=1;j<=a;++j) s+=b;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++) if(s[i]!=s[len-i-1]) minx++;
	cout<<minx;
	return 0;
}
