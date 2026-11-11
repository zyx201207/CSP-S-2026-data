#include <iostream> 
using namespace std;
const long long N = 500005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[N],ans = 0,x,mx;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 2;i <= n;i++)
	{
		int c = m;
		int mxx = 0;
		for (int j = 1;j <= n;j++)
		{
			int d = a[i] - a[j];
		    c -= d;
		    if (c >= 0 && d >= 0)
		   	{
	     		mxx++;
		   		if (mxx > ans)
		    	{
		    		ans = mxx;
				}
				else
				{
				    continue;
				}
		    }
			else
			{
				continue;
			}
		}
    }
	cout << ans;
	return 0;
}
