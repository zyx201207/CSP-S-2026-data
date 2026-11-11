#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll n,m,x,y,ans,u=1,rt,x_x,y_y;
ll a[N],book[N];
bool cmp(ll x,ll y){
	return x<y;
}
void check(ll k)
{
	if(k>n)
	{
		rt=1;
		return;
	}
	if(book[k]==1)
	{
		check(k+1);
	}
	else
	{
		if(x==1e5)
		{
			x=a[k];
			x_x=k;
			check(k+1);
		}
		else
		{
			y=a[k];
			y_y=k;
			return ;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	while(m!=0)
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				y=x=1e5;
				check(i);
				if(rt==1)
				{
					cout<<ans+4<<" \n";
					return 0;
				}
				if(y==1e5)
				{
					cout<<ans+3<<" \n";
					return 0;
				}
				if(x==y)
				{
					ans++;
					book[x_x]=1;
					book[y_y]=0;
					sort(a+1,a+1+n,cmp);
					continue;
				}
				if(y+u==x)
				{
					m-=u;
					ans++;
					a[y_y]=a[x_x]=a[y_y]+u;
					book[x_x]=1;
					book[y_y]=0;
					sort(a+1,a+1+n,cmp);
					continue;
				}
				book[x_x]=1;
			}
			u++;
		}
		
		if(u>m)
		{
			cout<<ans+4<<" \n";
			return 0;
		}
	}
	cout<<ans+4<<" \n";
	return 0;
}
