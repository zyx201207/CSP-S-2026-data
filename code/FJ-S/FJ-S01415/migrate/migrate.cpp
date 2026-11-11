#include<bits/stdc++.h>
using namespace std;
long long n,c,d,t,a[2000010],s,l;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		s=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=j-1;k>=1;k--)
//			{
//				s[j]=s[k]+s[j];
//			}
//		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]+d>=a[j+1]&&a[j]+d>=a[j+2]&&a[j]+d<a[j+3]&&a[j+1]+d>=a[j+3]&&a[j+2]+d>=a[j+3])
			{
				s++;
				//cout<<j<<" "<<j+3<<endl;
			}	
		}
		cout<<s<<endl;
	}
	return 0;
}
//1 1 2 4 8
//1 2 3 4 5 6
//
//6 2
//-4 -3 -2 -1 3 6

