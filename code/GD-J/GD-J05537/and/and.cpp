#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5+5;

int a[N][35];
bool nvis[N];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		int c;
		cin >> c;
		for(int j=30;j>=0;j--)
		{
			if((c>>j)&1==1)
			{
				a[i][j] = 1;
			}
		}
	}
	
	int ans = 0;
	for(int i=30;i>=0;i--)
	{
		int k =0 ;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1 && nvis[j]==0) k++;
		}
		if(k>=m) 
		{
			ans |= (1<<i);	
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]!=1)
				{
					nvis[j] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
