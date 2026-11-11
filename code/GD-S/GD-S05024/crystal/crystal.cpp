#include <iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long m,n,i;
	cin>>n>>m;
	int a[n];
	if(n>0&&m>=0)
	{
		for(i=0;i<=n-1;i++)
		{
			cin>>a[i];
		}
		int k,l;
		bool yn;
		do
		{
			for(k=0;k<=n-2;k++)
			{ 
				if(a[k]>a[k+1])
				{
					a[k]^=a[k+1];
					a[k+1]^=a[k];
					a[k]^=a[k+1];
				}
			}
			for(l=0;l<=n-2;l++)
			{
				yn=a[l]<=a[l+1]&&a[l+1]<=a[l+2];
			}
		}
		while(yn!=0);
		int j,h,s,u,u_0;
		for(j=1;;j++)
		{
			for(h=0;h<=j-1;h++)
			s+=a[h];
			u=a[j]*j-s;
			if(u<=0)
			{
				u_0=a[j-1]*j-s;
				break;
			}
		}
		cout<<u_0<<endl;
	}
	return 0;
}
