#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int a[10005];
char oc[10005];
long long f(int n) {
	for(int i=1; i<=n; i++)a[i]+=a[i-1];
	return a[n];
}
int main() {
	a[0]=0;
	long long n;
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		cin>>oc[i];
	}
	long long t=f(n*2);
	for(int i=t/2+1; i<=t; i++) {
		if(oc[i]==oc[t-i+1])continue;
		else if(oc[i]!=oc[t-i+1])ans+=1;
	}
    printf("%lld",ans);
	return 0;
}
