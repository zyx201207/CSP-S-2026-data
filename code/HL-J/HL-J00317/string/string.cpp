#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
int a[N];
int s[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		char c;
		cin>>c;
		s[i]=c-'a';
	}
	int i=1,j=n;
	while (i<j)
	{
		int k=min(a[i],a[j]);
		if(s[i]!=s[j])ans+=k;
		if(a[i]>a[j]) 
		{
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i]<a[j]) 
		{
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
		else if(a[i]==a[j])
		{
			a[i]=a[j]=0;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
