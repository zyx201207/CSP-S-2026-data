#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	long long n,a[200005],numa=0;
	char c;
	string s;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c;
		s=s+c;
	}
	string ss=s;
	reverse(ss.begin(),ss.end());
	long long ans=0;
	if(n%2==0){
		n/=2;
	}
	else{
		n=n/2+1;
	}
	for(long long i=0;i<n;i++){
		if(s[i]!=ss[i]) ans+=a[i];
	}
	printf("%lld",ans);
	return 0;
}
