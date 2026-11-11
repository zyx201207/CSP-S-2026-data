#include <bits/stdc++.h>
using namespace std; 
#define ll long long
const ll N=2e5+1000;
ll n,m=0,lmid,rmid,l,r;
ll a[N][2];
ll f(ll pos)
{
	ll num=a[1][1];
	for(int i=1;i<=n;i++)
	{
		if(pos>=a[i][0])
		{
			pos-=a[i][0];
			num=a[i][1];
		}
		else break;
	}
	return num;
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
    	ll x,y;
    	char c;
    	cin>>x>>c;
    	y=c-'a';
    	a[i][0]=x;
    	a[i][1]=y;
    	m+=x;
	}
	if(m%2==1)
	{
		lmid=(m+1)/2;
		rmid=lmid;
	}
	else {
		lmid=m/2;
		rmid=lmid+1;
	}
	l=1;r=m;
	ll cnt=0;
	while(l<=lmid&&r>=rmid)
	{
		ll p=f(l),q=f(r);
		if(p!=q)cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}

