#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans;
int a[200010];
char c[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,t=n;t>i;)
	{
		if(a[i]<a[t])
		{
			a[t]-=a[i];
			if(c[i]!=c[t])ans+=a[i];
			i++;
		}
		else if(a[i]>a[t])
		{
			a[i]-=a[t];
			if(c[i]!=c[t])ans+=a[t];
			t--;
		}
		else 
		{
			if(c[i]!=c[t])ans+=a[t];
			i++;
			t--;
		}
	}
	cout<<ans;
	return 0;
}
