#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;)
	{
		long long t=min(a[i],a[j]);
		//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<t<<"\n"; 
		if(c[i]!=c[j])ans+=t;
		a[i]-=t,a[j]-=t;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	return 0;
} 
