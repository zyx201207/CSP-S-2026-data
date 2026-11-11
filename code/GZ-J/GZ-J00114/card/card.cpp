//GZ-J00114 ÍõÕıÅí 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
ll h[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		flag=0;
	}
	if(flag)
	{
		ll sum=1,j=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=j)
				h[j]=sum,j=a[i];
				sum++;
		}
		h[j]=sum;
		for(int i=1;i<=m;i++)
		cout<<h[i]<<' ';
	}
	for(int i=1;i<=m;i++)
	{
		ll ans=0;
		for(int j=1;j<=n;j++)
		{
			vector<ll>v;
			ll k=j;
			for(;k<=n;k++)
			{
				for(int i=0;i<v.size();i++)
					if(v[i]==a[k])
						while(v.size()&&v.back()!=a[k])
							v.pop_back();
				if(v.size()&&v.back()!=a[k]||v.size()==0)
				v.push_back(a[k]);
			}
			bool flag=0;
			for(int l=0;l<v.size();l++)if(v[l]==i){flag=1;break;}
			ans+=flag; 
		}
		cout<<ans<<" ";
	}
	return 0;
}
