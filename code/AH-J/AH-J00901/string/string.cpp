#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
long long sum,ans,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ans=ans+a[i];
	}
	int i=1,j=n;
	while(s<ans/2)
	{
		s++;
		if(c[i]!=c[j])
		{
			sum++;
		}
		a[i]--,a[j]--;
		if(a[i]<=0) i++;
		if(a[j]<=0) j--;
	}
	cout<<sum;
}
