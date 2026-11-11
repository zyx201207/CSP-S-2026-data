#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],max1=INT_MIN,b[200010],k,s,c1,c2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(m==1)
	{
		cout<<max1;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			if(a[j]>a[j-1])
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		k=1;
		while(a[i]!=0)
		{
			b[i]+=a[i]%2*k;
			k*=10;
			a[i]/=2;
		}
	}
	for(int i=1;i<m;i++)
	{
		s=0;
		k=1;
		for(int j=1;j<=max(b[i],b[i+1]);j*=10)
		{
			c1=b[i]/j%10;
			c2=b[i+1]/j%10;
			if(c1==c2)
			{
				s+=k;
			}
			if(c1!=c2)
			{
				s+=0;
			}
			k*=10;
		}
		b[i+1]=s;
	}
	s=0;
	k=1;
	for(int i=1;i<=b[m];i*=10)
	{
		s+=b[m]/i%10*k;
		k*=2;
	}
	cout<<s;
	return 0;
}

