#include <iostream>
#include <algorithm>
using namespace std;
int d;
int dy[2000005];
int way[100000000];
int num = 0;
int check(int i,int j)
{
	if(dy[j] - dy[i] <= d)
	{
		return 1;
	}
	else
	{
		int cnt = 1;
		int op = 887767890;
	    while(dy[i+cnt] - dy[i] <= d)
	    {
	    	op = min(op,check(i+cnt,j)+1);
		}
		return op;
    }
}
void qindian(int i, int j, int sum)
{
	if(dy[j] - dy[i] <= d)
	{
		num++;
		sum++;
		dy[num] = sum;
	}
	else
	{
		int cnt = 1;
		while(dy[i+cnt] - dy[i] <= d)
		{
			qindian(i+cnt,j,sum+1);
			cnt++;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	int u;
	cout << 1;
	cin >> t >> u;
	for(int p = 1; p <= u; p++)
	{
		int n;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> dy[i];
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				int ok = check(i,j);
				qindian(i,j,0);
				int snm = 0;
				for(int i = 1; i <= num; i++)
				{
					if(way[i] == ok)
					{
						cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
    }
	return 0;
}
