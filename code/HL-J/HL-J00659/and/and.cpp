#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ll n,m,a[100010],ans1,p[32],ne[100010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll t=1073741824,tp=31,te=0,tpp=31,b,e;
	for(int i=1;i<=n;i++)
	{
		while(t>a[i])
		{
			t/=2;
			tp--;
		}
		p[tp]++;
		if(p[tp]>=m)
		{
			b=i-m+1;
			e=i;
			break;
		}
	}
	ll tt=pow(2,tpp),len=e-b+1;
	for(int i=1;i<=len;i++)
	{
		ne[i]=a[b+i-1]%tt;
	}
	sort(ne+1,ne+1+len,cmp);
	ans1=ne[1];
	for(int i=2;i<=m;i++)
	{
		ans1=(ans1&ne[i]);
	}
	cout<<ans1;
    return 0;
}

