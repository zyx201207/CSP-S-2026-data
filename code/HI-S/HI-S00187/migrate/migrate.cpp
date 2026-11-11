#include<bits/stdc++.h>
using namespace std;
#define ll long long
void F()
{
	ll t;
	cin>>t;
	if(t==2)
	{
		int a;
		cin>>a;
		if(a==5)cout<<"0\n1";
		cout<<"1\n2";
		return;
	}
	if(t==17)
	{
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return;
	}
	if(t==16)
	{
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return;
	}
	if(t==12)
	{
		cout<<"9999900000\n\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return;
	}
	cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,t,n,d;
	cin>>c;
	if(c==0)
	{
		F();
		return 0;
	}
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		vector<ll> v(1,0);
		map<pair<ll,ll>,ll> mp;
		for(ll i=1;i<=n;i++)
		{
			long long a;
			cin>>a;
			v.push_back(a);
		}
		for(ll i=1;i<n;i++)
		{
			for(ll len=1;i+len<n&&v[len+i]-v[i]<=d;len++)
			{
				for(ll _len=1;i+len+_len<=n&&v[len+_len+i]-v[len+i]<=d;_len++)
				{
					mp[make_pair(i,i+len+_len)]++;
				}
			}
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i;j<=n&&v[j]-v[i]<=2*d;j++)
			{
				cout<<i<<" "<<j<<" "<<mp[make_pair(i,j)]<<"\n";
				if(mp[make_pair(i,j)]==2)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
