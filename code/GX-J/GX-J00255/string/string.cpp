#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		char b;
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];++j)s+=b;
	}
	int j=s.size()-1;
	int l=s.size()/2;
	for(int i=0;i<l;++i){
		if(s[i]!=s[j])++ans;
		--j;
	}
	printf("%lld",ans);
}
