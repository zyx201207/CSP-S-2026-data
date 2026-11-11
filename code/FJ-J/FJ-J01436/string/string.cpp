#include<bits/stdc++.h>
using namespace std;
int a[100001];
char c[100001];
int n;
char s[10000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
		{
			s[t]=c[i];
			t++;
		}
	}
	int sum=0;
	for(int i=1;i<=ans/2;i++)
	{
		if(s[i]!=s[ans+1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
