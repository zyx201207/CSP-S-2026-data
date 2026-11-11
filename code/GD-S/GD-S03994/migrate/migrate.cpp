#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;

int c,T,n;
long long d,x[N],s;


void dfs(int l, int r, long long cnt,long long p)
{
	if(p == cnt)
	{
		s++;
	}
	for(int i = l+1; i <= r; i++)
	{
		long long q = x[i] - x[l];
		if(q <= d)
		{
			p += q;
			dfs(i,r,cnt,p);
			p -= q;
		}
			
	}
}


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
 
	while(T--)
	{
		long long ans = 0;
		memset(x,0,sizeof(x));
		cin >> n >> d;
		for(int i = 1;i <= n; i++)	cin >> x[i];
		
		
		for(int i = 1; i < n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				dfs(i,j,x[j]-x[i],0);
				
				if(s == 2)
					ans++;
				s = 0;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
 } 
