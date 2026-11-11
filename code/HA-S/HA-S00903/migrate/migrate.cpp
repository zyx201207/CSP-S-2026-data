#include<bits/stdc++.h>
using namespace std;
int l[2000001];
int a[2000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin>>c>>t;
	for(int i = 0; i < t; i++)
	{
		int n,d;
		cin>>n>>d;
		long long x[n+1];
		for(int i = 0; i < n; i++)
		{
			cin>>x[i];
		}
		cout<<1;
		
		int sum = 0;
		for(int ii = 0; ii < min(n,d); ii++){
			for(int i = 0; i < n-1; i++)
			{
				int eq = n;
				for(int j = eq; j >= 1; j--)
				{
					if(x[i]+j==x[i+1]){
						a[i]=1,a[i+1]=1;
						i=j;
						l[ii]+=i;
						eq=j;
						break;
					}
					 
				}
			}
		}
		int ans = 0;
		for(int i = 1; i < n-2; i++){
			if(l[i]!=l[i-1]){
				ans++;
			}
		}
		cout<<ans;
		
	}
	
	return 0;
} 
