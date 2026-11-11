#include<bits/stdc++.h>
using namespace std;
long long b[200005];
long long a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long mid=0,k=0;

	char c[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		a[i]+=a[i-1]; 
	}
	mid=(a[n]+1)/2;
	int x=1;
	for(int i=1;i<=n;i++)
	{
		b[x]=a[i];
		b[x+1]=2*mid-a[i];
		x+=2;
	}
	b[x]=mid;
	sort(b,b+x+1);
	for(int i=0;i<=x;i++)
	{
		if(b[i]==b[i+1]) b[i]=0;
	}
	sort(b,b+x+1);
	int p=0;
	for(int i=0;i<=x;i++)
	{
		if(b[i]!=0)
		{
			p=i;
			break;
		}
	}
	for(int i=p;i<=x;i++)
	{
		if(i>=(x+p-i)) break;
		long long l=b[i],r=b[x+p-i];
		char z1,z2;
		for(int j=0;j<n;j++)
		{
			if(l>a[j]&&l<=a[j+1]) z1=c[j+1];
		}
		for(int j=0;j<n;j++)
		{
			if(r>a[j]&&r<=a[j+1]) z2=c[j+1];
		}
		if(z1!=z2) k+=(b[i]-b[i-1]);
	}
	cout<<k;
	
	return 0;
 } 
