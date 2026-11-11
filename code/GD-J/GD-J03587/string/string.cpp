#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
struct fw
{
	ll a;
	char c;	
}f[N];
int n;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i].a >>f[i].c ;
	}
	int l = 1, r = n;
	while(l < r)
	{
		ll cost = min(f[l].a,f[r].a);
		if(f[l].c != f[r].c )
		{
			ans += cost;		
		}
		f[l].a -= cost;
		f[r].a -= cost;
		if(!f[l].a) l++;
		if(!f[r].a) r--;
	}
	cout<<ans;
	return 0;
} 
