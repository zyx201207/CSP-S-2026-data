#include<bits/stdc++.h>
using namespace std;
long long LYY,T;
long long n,d,a[2000010];
long long dqr()
{
	long long s=0;
	for(int i=1;i<n;i++)
	{
		long long w=0;
		if(a[i]+d>=a[n])
		{
			break;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-d>a[i])
			{
				w=j;
				break;
			}
		}
		if(w-2<=i)
		{
			continue;
		}
		long long x=w-2;
		long long l=w-1;
		long long bs1=1,bs2=1;
		for(int j=w;j<=n;j++)
		{
			if(bs1==bs2&&a[l]+d>=a[j]&&a[x]+d>=a[j]&&a[x-1]+d<a[j])
			{
		//		cout<<x<<" "<<l<<" "<<j<<"\n";
				s++;
			}
			bool f=0;
			if(a[j]-a[l]>d)
			{
				l=j-1;
				bs2++;
				if(bs1<bs2)
				{
					x=j-2;
					bs1++;
				}
				f=1;
			}
			if(a[j]-a[x]>d)
			{
				if(f==1)
				x=j-2;
				else
				x=j-1;
				bs1++;
			}
		}
	}
	return s; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>LYY>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=5000)
		{
			cout<<dqr()<<"\n";
		}
		else
		{
			bool f=0;
			long long c=a[2]-a[1];
			for(int i=3;i<=n;i++)
			{
				if(a[i]-a[i-1]!=c)
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				long long s=0;
				long long w=d/c;
				if(w<=1)
				{
					cout<<0<<"\n";
					continue;
				}
				if(n-d-d+1<=0)
				{
					cout<<"0\n";
				}
				long long r=1;
				for(int i=1;i<=n-d+1;i+=d)
				{
					s+=r;
					r++;
				}
				
				cout<<s<<"\n";
			}
			else
			{
				cout<<dqr()<<"\n";
			}
		}
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
