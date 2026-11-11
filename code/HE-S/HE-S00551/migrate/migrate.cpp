#include <iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int x[100000];
	int l[100000];
	int ct[100000];
	int s,r;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		r=0;
		for(int j=0;j<n;j++)
		{
			cin>>x[j];
		}
		cout<<endl;
		for(int j=0;j<n-1;j++)
		{
			s=j;
			l[j]=0;
			ct[j]=1;
			for(int k=j+1;k<n;k++)
			{
				ct[k]=0;
				while((x[k]-x[s])>d)
				{
					s++;
				}
				if(s==k)
				{
					break;
				}
				l[k]=l[s]+1;
				for(int p=s;l[p]==l[s];p++)
				{
					ct[k]+=ct[p];
				}
				if(ct[k]==2)
				{
					r++;
				}
			}
		}
		cout<<r<<endl;
	}
	return 0;
}
