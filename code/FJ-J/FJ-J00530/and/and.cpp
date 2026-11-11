#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll s[200005];//数据 
int t[200005][31];//二进制 
ll k[200005];//每个数位 
int h[200005];//是否留下 
ll n;
void two(ll i,ll n)
{
	ll len=0;
	while(n!=0)
	{
		t[i][len+1]=n%2;
		n/=2;
	}
}
ll check(int line)
{
	ll f;
	for(int i=1;i<=30;i++)
	{
		if(t[line][i] && h[i]==0)f++;
	}	
	return f;
}
void use(int time,ll m,ll los){
	if(los==m)return ;
	if(time==0)return ;
	if(m<=0)return ;
	for(int i=1;i<=n;i++)
	{
		if(h[i]>0)h[i]++;
	}
	if(k[time]>=m)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[j][time]==0 && h[j]!=-1)
			{
				if(h[j]==0)
				{
					h[j]=1;
					los--;
				}
			}
		}
	}
	ll o=0;
	if(los<m)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[j][time]==0)
			{
				t[j][time]=-1;
				o++;
			}
			if(t[j][time]==1)
			{
				t[j][time]=0;
			}			
		}			
		use(time-1,m-o,los);
	}
	else use(time-1,m,los);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	if(n==m)
	{
		for(int i=2;i<=n;i++)
		{
			s[1]=s[1]&s[i];
		}
		cout<<s[1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		two(i,s[i]);
	}
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[j][i])k[i]++;
		}
	}
	ll los=n;
	use(30,m,los);
	ll g=1073741823;
	for(int i=1,j=0;i<=n,j<m;i++)
	{
		if(h[i]==0 || h[i]==-1)
		{
			g&=s[i];
			j++;
		}
	}
	cout<<g;
	return 0;
}
