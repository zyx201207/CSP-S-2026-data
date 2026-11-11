#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200005

int n,m;

vector<int> arr[32];

ll as[MAXN];

int anx = 0;
ll ans = 0;
int anl = 0;


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;

	ll a;
	for(int i = 1; i <= n; i++)
	{
		cin >> a;
		as[i] = a;
	
		int f = 1;
		
		while(a > 0)
		{
			if(a % 2 == 1) arr[f].push_back(i);
			a /= 2;
		}
		
	}
	
	
	for(int i = 1; i <= 30; i++)
	{
		int l = arr[i].size();
		
		if(l == m)
		{
			anx = i;
			break;
		}
	}

	anl = arr[anx].size();

	for(int i = 1; i < anl; i++)
	{
		ans = as[ arr[anx][i - 1] ] & as[ arr[anx][i] ];
		as[ arr[anx][i] ] = ans;
	}
	
	cout << ans;
	
	
	return 0;
}
