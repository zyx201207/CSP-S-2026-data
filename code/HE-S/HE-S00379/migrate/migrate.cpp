#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int c, t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		int n, d, id[N];
		cin >> n >> d;
		int cha[N];
		int max_cha = 0;
		for(int i = 1;i <= d; i++)
		{
			cin >> id[i];
			if(i >= 1)
				cha[i-1] = id[i] - id[i - 1];
			max_cha =  max(max_cha, cha[i-1]);
		}
			
		if(id[d] - id[d-1] == id[d-1] - id[d-2])
		{
			if(max_cha >= (3 * (id[d] - id[d-1])))
			{
				cout << 0 << '\n';
				continue;
			}else
			{
				d -= 4;
				cout << d << '\n';
			}
		}
	}
	//如果这样能拿分,我做什么都会愿意的 
	return 0;
}
