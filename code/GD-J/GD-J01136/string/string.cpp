#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,sum;
int a[200000+10];
char c[200000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cin>>c[i];
		sum+=a[i];
	}
	if(sum%2==0)sum/=2;
	else sum=(sum+1)/2;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		t+=a[i];
		if(sum<=t){
			k=i;
			break;
		}
	}
	for(int i=1,j=n;i<k,j>=k;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>=a[j])ans+=a[j],a[i]-=a[j],j--;
			else ans+=a[i],a[j]-=a[i],i++;
		}
		else{
			if(a[i]>=a[j])a[i]-=a[j],j--;
			else a[j]-=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}
