#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n];
	int s=0,b=0;        
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<s)
		{
			s=a[i];
		}
		if(a[i]>b);
		b=a[i];
	}
	int max=n;
	for(int j=0;j<n;j++)
	{
		if(max<=2)
			{
				break;
			}
		for(int i=0;i<n;i++)
		{
			if(a[i]==s||a[i]==b)
			{
				cout<<a[i]<<endl;
				break;
			}
		}
		break;
	}
	return 0;
}
