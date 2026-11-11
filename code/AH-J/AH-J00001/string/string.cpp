#include <bits/stdc++.h>
using namespace std;
const int N = 200000+5;
int n;
long long a[N];
char ch[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	int i=1,j=n;
	while(i<=j)
	{
		if(ch[i]!=ch[j])
		{
			if(a[i]>a[j])
			{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else
			{
				ans+=a[i];
				i++;
				j--;
			}
		}
		if(ch[i]==ch[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j])
			{
				a[j]-=a[i];
				i++;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
