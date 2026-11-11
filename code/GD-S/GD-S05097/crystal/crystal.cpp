#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=500005;
ll n,m,ans,a[MAXN],pre[MAXN]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool sp=1;
	ll tes=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(tes!=(a[i]-a[i-1])&&i>2)
//			cout<<i<<" !"<<endl;
			sp=0;
		tes=a[i]-a[i-1];
//		cout<<tes<<endl;
	}
	//
//	cout<<sp<<" "<<tes<<endl;
	//
	sort(a+1,a+n+1);
	
	pre[1]=a[1]; 
	for(ll i=2;i<=n;i++)
		pre[i]=pre[i-1]+a[i];

	if(sp)
	{
		for(ll i=1;i<=n;i++)
		{
			ll fm=(a[i]*i)-pre[i];
			//
//			cout<<a[i]<<endl<<x<<" "<<(a[i]*i)<<" "<<fm<<endl;
			//
			if(fm==m)
			{
				ans=i;
				break;
			}
			if(fm>m)
			{
				ans=i-1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	//
//	for(ll i=1;i<=n;i++)
//	{
//		cout<<pre[i][0]<<" "; 
//	}
//	cout<<endl;
//	for(ll i=1;i<=n;i++)
//	{
//		cout<<pre[i][1]<<" ";
//	}
//	cout<<endl;
	//
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n-i;j++)
		{
			ll x=pre[j]-pre[i]+a[i];
			ll fm=(a[j]*(j-i+1))-x;
			if(fm==m)
			{
				ll res=j-i+1;
				ans=max(ans,res);
				if(a[j]!=a[j+1])
					break;
			}
			if(fm>m)
			{
				ll res=j-i;
				ans=max(ans,res);
				if(a[j]!=a[j+1])
					break;
			}
		}
	}
	cout<<ans;
	return 0;
} 

/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
