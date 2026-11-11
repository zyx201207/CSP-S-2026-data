#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int a[N], ans[M];
int n, m;

int main()
{

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    if( n <= 500)
    {
        for(int i = 1; i <= n; i++)//枚举局数， 1~n
        {
            int s[550] = {}, last = 1;
            for(int j = i; j <= n; j++)
            {
                int nowcard = a[j], idx = 0, findk = 0;
                bool flag = false;
                for(int k = 1; k <= last; k++)
                {
                	if(s[k] == nowcard)
                	{
						findk = k;
						flag = true;
						break;
					}
				}
				if(flag)
				{
					for(int k = findk; k <= last; k++)
						s[k] = 0;
					s[findk] = a[j], last = findk;
				}
				else
					s[last + 1] = a[j], last++;
            }
			for(int k = 1; k <= last; k++)
			{
				int nown = a[k];
		    	ans[nown]++;
			}
        }
        for(int i = 1; i <= m; i++)
        	cout<<ans[i]<<" ";
    }
    return 0;
}
