#include<iostream>
using namespace std;
const int N=2e6+5;
int c,t;
int a[N];
int main()
{
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>c>>t;
	
	while(t--)
	{
	
		int n,d;
		cin>>n>>d;
	
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<a[n]/d;
	}
}
