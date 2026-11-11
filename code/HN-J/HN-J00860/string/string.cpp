#include<bits/stdc++.h>
using namespace std;
int a[200010],c[200010],sum2[200010];
long long s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>a[i]>>cc;
		c[i]=cc-'a';
	}
	
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[i];
	int sum1=0,ans=0,r=n;
	long long mid=(s[1]+1)/2;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(r==i){
			ans+=a[i]-sum2[r];
			break;
		}
		while(a[r]-sum2[r]<=a[i]){
			if(r==i)break;
			if(c[r]==c[i])ans+=(a[r]-sum2[r])*2;
			a[i]=a[i]-a[r]+sum2[r],r--;
		}
		if(sum1>=mid){
			ans+=a[i];
			break;
		}
		if(a[r]-sum2[r]>a[i]){
			if(c[r]==c[i])ans+=2*a[i];
			sum2[r]+=a[i];
		}
	}
	cout<<(s[1]-ans)/2;
	return 0;
}
