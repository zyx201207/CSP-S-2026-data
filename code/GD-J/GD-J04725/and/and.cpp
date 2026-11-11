#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500000],b[500000],c[500000],maxn,bj,x;
string s;
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long p,sum=0;
		p=a[i];
		while(p!=0)
		{
			int o;
			o=p%2;
			if(o==1)
			{
				sum++;
			}
			p/=2;
		}
		b[i]=sum;
	}
	for(int k=0;k<m;k++)
	{
		for(int i=1;i<=n;i++)
	    {
		   if(b[i]>maxn)
		   {
		   	 maxn=b[i];
		   	 bj=i;
		   }
		   else if(b[i]==maxn)
		   {
		   	 if(a[i]>a[bj])
		   	 {
		   	 	bj=i;
			 }
		   }
	    }
	    c[k]=a[bj];
	    a[bj]=0;
	    b[bj]=0;
	    maxn=0;
	}
	x=c[0];
	for(int i=1;i<m;i++)
	{
		x&=c[i];
	}
	cout<<x<<endl;
	return 0;
}
