//GZ-S00322◊Ò“ÂÀƒ÷–’‘’Ò”Ó
#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n,m; 
ll a[N];
ll b[N];
ll ans;
ll mn=1e13;
ll mx=-1e13;
ll last;
int idx;
bool flag1=true;
bool flag2=true;
bool cmp(ll a,ll b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			flag1=false;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		if(i>1&&b[i]!=b[i-1])
			flag2=false;
	}
	if(flag1||flag2)
	{
		ll cha=a[2]-a[1];
		ll v=cha;
		while(m)
		{
			if(m<v)
				break;
			m-=v;
			v+=cha;
			ans++;
		}
		cout<<ans+1<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(b[i]<mn)
		{
			mn=b[i];
			idx=i;
		}
	}
	int i=idx-2,j=idx+1;
	if(m<b[idx])
	{
		cout<<1<<endl;
		return 0;
	}
	m-=b[idx];		
	mx=a[idx];
	int cnt=0;
	while(m)
	{
		if((i<1&&j>n)||(i<1&&m<(a[j]-mx)*(j-i-1))||(j>n&&m<mx-a[i])||(m<mx-a[i]&&m<(a[j]-mx)*(j-i-1)))
			break;
		if((mx-a[i]<(a[j]-mx)*(j-i-1)&&i>0)||(j>n&&i>0))
		{
			m=m-(mx-a[i]);
			i--;
			ans++;
		}
		else if((mx-a[i]<(a[j]-mx)*(j-i-1)&&j<n+1)||(i<1&&j<n+1))
		{
			m=m-(a[j]-mx)*(j-i-1);
			mx=a[j];
			j++;
			ans++;
		}
	}
	cout<<ans+2<<endl;
	return 0;
}

