#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
#define fr(i,e,s) for(int i=e;i>=s;i--)
using namespace std;
typedef long long ll;
const ll N=5e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N];
ll s[N],su[5060][5060];
ll ok[N];
ll ans=1;
void dfs(int x)
{
	if(x>n)
	{
		ll maxx=0,sp=0,sum=0;
		fr(i,n,1)
		{
			if(ok[i])
			{
				maxx=a[i];
				break;
			}
		}
		f(i,1,n) if(ok[i])
		{
			sp+=(maxx-a[i]);
			sum++;
		} 
		if(sp<=m)
		{
//			f(i,1,n) if(ok[i]) cout<<a[i]<<" ";
//			cout<<endl<<maxx<<" "<<sp<<endl<<endl;
			ans=max(ans,sum);
		}
		return;
	}
	ok[x]=1;
	dfs(x+1);
	ok[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
//	dfs(1);
//	cout<<ans;
	f(i,2,n)
	{
		ll d=a[i]-a[i-1];
		s[i]=s[i-1]+d*(i-1);
//		cout<<a[i]<<" "<<a[i-1]<<"  "<<d<<" "<<s[i]<<endl;
	}
	f(i,1,n)
	{
		f(j,1,i)
		{
			su[i][j]=su[i][j-1]+(a[i]-a[j]);
//			cout<<su[i][j]<<" ";
		}
//		cout<<endl;
	}
	f(i,1,n)
	{
		f(j,1,i-1)
		{
			if((su[i][i]-su[i][j-1])<=m)
			{
//				cout<<j<<" "<<i<<"  "<<su[i][i]-su[i][j-1]<<endl;
				ans=max(ans,(ll)i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}























































