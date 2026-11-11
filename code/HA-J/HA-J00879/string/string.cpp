#include <iostream>
using namespace std;
int n,a;
int ans,f;
string c[10005],b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n;i++)
	{
		cin >> a >> b;
		f += a;
		for(int j = 1; j <= a;j++)
	    {
	        c[i] = b;
		}
	}
	int e = f/2;
	
	for(int k = e;k >= 1;k--)
	{
		for(int d = 1;d <= e;d++)
		{
		    if(c[k] != c[d])
	    	{
		    	ans++;
		    	
		    }
		}
	}
	cout << ans;
	return 0;
}
