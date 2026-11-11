#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
char c[1000000000],ca[200005];
long long ac[200005];
int n,top=0,ii,top1;
long long sum,sl;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sl+=a[i];
		a[i]+=a[i-1];
		if(c[i]==c[i-1])
			ac[top]=a[i];
		else
			ac[++top]=a[i],ca[top]=c[i];
	}
	if(top==1)
	{
		cout<<0;
		return 0;
	}
	if(top==2)
	{
		cout<<min(ac[2],ac[1]);
		return 0;
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i]-a[i-1];j++)
		{
			ca[++t]=c[i];
		}
	}
	int n1=0;
	if(t%2==0)
	n1=t/2;
	else
	n1=(t-1)/2; 
	for(int i=1;i<=n1;i++)
	{
		if(ca[i]!=ca[t-i+1])
		sum++;
	}
	cout<<sum;
	return 0;
} 
