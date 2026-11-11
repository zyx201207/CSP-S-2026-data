#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long i=1,j=n;
	while(1)
	{
		if(a[i]>=a[j])
		{
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
			if(a[i]==0)i++;
		}
		else
		{
			if(c[j]!=c[i])ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
			if(a[j]==0)j--;
		}
		if(i>=j)break;
	}
	cout<<ans;
	return 0;
}
