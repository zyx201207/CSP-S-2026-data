#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100001],ans=0,s[100001];
	char b[100011];
	string c;
	cin>>n;
	s[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s[i]=s[i-1]+a[i];
}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1,j=1;i<=s[n];i++){
		if(i>s[j])j++;
		c[i]=b[j];
	}
	for(long long i=1;i<=s[n]/2;i++){
		if(c[i]!=c[s[n]+1-i])ans++;
	}
	cout<<ans;
	return 0;
}
