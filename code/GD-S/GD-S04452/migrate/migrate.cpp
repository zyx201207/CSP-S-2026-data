#include <iostream>
using namespace std;

int c,t;
unsigned long long l,d;
int n,lmax,cnt;
long long a[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==11||c==12)
	{
		for(int i=0;i<t;i++)
		{
			cin>>n>>d;
			for(int j=0;j<n;j++)
			{
				cin>>a[j];
			}
			l=a[1]-a[0];
			if((d<l)||(d%l==0&&d/l>n)||(a[n-1]-a[0]<d))
			{
				cout<<0<<endl;
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					if(a[j]-a[0]>l)
					{
						lmax=j;
						break;
					}
				}
				lmax--;
				cnt=(n-1)/lmax;
				cnt--;
				cout<<cnt<<endl;
			}
		}
	}
	else
	{
		for(int i=0;i<t;i++)
		{
            cin>>n>>d;
            for(int j=0;j<n;j++)
			{
				cin>>a[i];
			}
			l=a[n-1]-a[0];
			if(l<d)
			{
				cout<<n*(n-1);
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
