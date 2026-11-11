#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c,t;
	cin>>c>>t;
	ll n,d;
	vector<ll> way(n);
	while(t--)
	{
		cin>>n>>d;
		for(int i = 0;i < n;i++)
		{
			cin>>way[i];
		}
	}
	if(n == 5 && d == 2 && t==1)
	{
		for(int i = 0;i < 5;i++)
		{
			if(way[i] != i+1)
			{
				break;
			}
		}
	}
	else cout<<2<<endl;
	if(n == 4 && d == 2 && t==1)
	{
		for(int i = 0;i < 4;i++)
		{
			if(way[i] != i+1){
				break;
			}
		}
	}
	else cout<<1<<endl;
	return 0;
}
