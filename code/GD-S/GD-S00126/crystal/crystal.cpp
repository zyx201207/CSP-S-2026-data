#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[500001];
ll n,m,maa,mia,va1,va2,va;
ll ans;
int main()
{
	freopen("crystal.out","w",stdout);
	freopen("crystal4.in","r",stdin);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		va1+=a[i];
		maa=max(a[i],maa);
		mia=min(a[i],mia);
	}
	va1=(va-mia-maa)/(n-2);
	sort(a+1,a+1+n);
	va2=a[n/2+1];
	va=(va1+va2)/2; 
	cout<<va<<endl;
	for(ll i=n;i>=1&&m>=0;i--)
	{
		if(a[i]<=va&&m>=0&&m-(va-a[i])>=0)
		{
			//a[i]+=va-a[i];
			m-=va-a[i];
			//cout<<m<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

