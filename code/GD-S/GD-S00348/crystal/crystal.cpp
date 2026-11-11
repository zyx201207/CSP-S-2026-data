#include <iostream>
#include <algorithm>
using namespace std;
const int N=5*1e6+5;
long long a[N];
int main()
{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		int n;
		long long m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int res=0;
		int max=0;
		long long x=m;
		for(int j=1;j<=n;j++)
		{
			int t=a[j];
			m=x;
			res=0;
			for(int i=j;i>=1;i--)
			{
				if(t-a[i]<=m)
				{ 
					res++;
					m=m-t+a[i];
				}
			}
			if(max<res) max=res;
			//cout<<m<<' '<<max<<endl;
		}
		cout<<max;
		return 0;
}
