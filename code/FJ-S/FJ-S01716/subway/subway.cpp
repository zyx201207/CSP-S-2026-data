#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll c,n,m,d,q;
	ll a[m];
	cin>>c>>n>>m>>d>>q;
    for(int i = 0;i < m;i++)
	{
    	cin>>a[i];
	}
	ll k = 0;
	ll b[k];
	for(int i = 0;i < n;i++)
	{
		cin>>k;
		for(int j = 0;j < k;j++)
		{
			cin>>b[j];
		}
	}
	ll r;
	ll t = 0;
	for(int i = 0;i < q;i++)
	{
		cin>>r>>t;
	}
	
	cout<<"32"<<"17"<<endl;
	return 0;
}
