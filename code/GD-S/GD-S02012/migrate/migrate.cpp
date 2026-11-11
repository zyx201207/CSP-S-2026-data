#include<iostream>
#include<cmath>
using namespace std;
int island[50005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n,d;
		cin>>n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>island[j];
		}
		int num=0;
		for(int j=0;j<n;j++)
		{
			num+=island[j];
		}
		num/=n;
		num=num/d;
		cout<<num<<endl;
	}
}
