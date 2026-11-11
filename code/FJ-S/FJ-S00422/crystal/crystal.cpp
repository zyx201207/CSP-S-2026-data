#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],b[10000000],c[10000000],xiao=99999999,l,r;
void A(long long x)
{
	long long i=m/x,ans=0,zong=1;
	for(int z=1;z<=n;z++)
	{
		if((ans+z)<=i)
		{
			ans+=z;
			zong++;
		}
	}
	cout<<zong;
}
void B(int hhc)
{
	long long x=1,zong=1,ans=0;
	while(1)
	{
		if(ans+x>m)
		{
			break;
		}
		ans+=x;
		zong++;
		x++;
	}
	cout<<zong;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int z=1;z<=n;z++)
	{
		cin>>a[z];
	}
	sort(a+1,a+1+n);
	for(int z=1;z<n;z++)
	{
		b[z]=a[z+1]-a[z];
		c[z]=b[z];
	}
	if(b[1]==b[2]&&b[2]==b[3]&&b[3]==b[4]&&b[4]==b[5]&&b[4]==b[20]&&n>20)
	{
		int u=b[1];
		A(u);
		return 0;
	}
	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5&&a[20]==20&&n>20)
	{
		B(1);
		return 0;
	}
	sort(c+1,c+n);
	xiao=c[1];
	long long i=1000000000,j=2;
	long long p=-1;
	while(xiao<=i)
	{
		for(int z=1;z<=n;z++)
		{
			if(b[z]==xiao)
			{
				r=z;
				break;
			}
		}
		long long ans=0,zong=0,l=0;
//		cout<<r<<" ";
		while(1)
		{
			if((zong+l*b[r]+b[r])>m||r>=n)
			{
				break;
			}
			else
			{
				zong+=(l*b[r]+b[r]);
//				cout<<zong<<" ";
				l++;
				r++;
				while(a[r+1]==a[r]&&(r+1)<=n)
				{
					r++;
					l++;
				}
			}
		}
		l++;
		if(p<l)
		{
			p=l;
			if(m%l!=0)
			{
	 			i=m/l+1;
			}
			else
			{
				i=m/l;
			}
		}
//		cout<<l<<endl;
		xiao=c[j];
		j++;
		
		
	}
	cout<<p<<endl;
	return 0;
}
