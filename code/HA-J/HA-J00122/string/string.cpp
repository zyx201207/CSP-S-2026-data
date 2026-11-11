#include<bits/stdc++.h>
using namespace std;
int n,x[200005];
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>x[i]>>c[i];
	int l = 1,r=n;	
	int sum1=x[1],sum2=x[n];
	while(l<r){
		if(sum1>sum2){
			if(c[l]!=c[r])ans+=sum2;
			sum1-=sum2;
			r--;
			sum2=x[r];
			continue;
		}
		if(sum2>sum1){
			if(c[l]!=c[r])ans+=sum1;
			sum2-=sum1;
			l++;
			sum1=x[l];
			continue;
		}
		if(c[l]!=c[r])ans+=sum1;
		l++;
		r--;
		sum1=x[l];
		sum2=x[r];
	}
	cout<<ans;
	return 0;
}
