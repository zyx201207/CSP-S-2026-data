#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int C,T;
int n;
long long a[N],d,ans;
long long minn=1e18,cnt=0;
void dfs(int x,int to,int step)
{
	if(x==to)
	{
		if(minn>step) cnt=1,minn=step;
		else if(minn==step) cnt++;
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]>d) break;
		dfs(i,to,step+1);
	}
	return;
}
//------------------------------------------------------
int b[N],num=0,c[N],D[N],sum=0;
bool fshort(int x,int y)
{
	long long lpos=a[x];
	D[0]=x;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-lpos>d)
		{
			if(i-D[sum-1]<=1) return false;
			D[++sum]=i-1;
			lpos=a[i-1];
			i--;
		}
	}
	D[++sum]=y;
	return true;
}
bool check(int x,int y)
{
	long long lpos=a[x];
	b[0]=x;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-lpos>d)
		{
			if(i-b[num-1]<=1) return false;
			b[num++]=i-1;
			lpos=a[i-1];
			i--;
		}
	}
	b[num]=y;
	int cnum=num;
	lpos=a[y];
	c[0]=x;c[num--]=y;
	for(int i=y-1;i>=x;i--)
	{
		if(lpos-a[i]>d)
		{
			if(c[num+1]-i<=1) return false;
			c[num--]=i+1;
			lpos=a[i+1];
			i++;
		}
	}
	num=cnum;
	bool pd=false;
	for(int i=0;i<=num;i++)
		if(b[i]!=c[i])
		{
			pd=true;
			break;
		}
	return pd;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		if(C==1||C==2)
		{
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					{
						minn=1e18,cnt=0;
						dfs(i,j,0);
						if(cnt==2) ans++;
					}
			cout<<ans<<endl;
		}
		else if(C==11||C==12)
		{
			int ju=d/(a[2]-a[1]);
			if(ju<=1) cout<<0<<endl;
			else cout<<max(n-ju*2+1,0)<<endl;
		}
		else
		{
			for(int i=1;i<=n-3;i++)
				for(int j=i+3;j<=n;j++)
				{
					bool add1=1,add2=1;
					num=1;
					if(!check(i,j)) continue;
					for(int k=num-1;k>0;k--)
					{
						sum=0;
						if(!fshort(b[k]-1,j)) continue;
						if(sum==num-k)
						{
							//for(int l=0;l<=sum;l++)
							//	cout<<D[l]<<" ";
							//cout<<endl;
							add1=add2=1;
							for(int l=0;l<=sum;l++)
								if(D[sum-l]!=b[num-l])
								{
									add1=0;
									break;
								}
							for(int l=0;l<=sum;l++)
								if(D[sum-l]!=c[num-l])
								{
									add2=0;
									break;
								}
							if(!add1&&!add2) break;
						}
					}
					//if(add1||add2) cout<<i<<" "<<j<<endl;
					ans+=(add1||add2);
				}
			cout<<ans<<endl;
		}
	}
	return 0;
}

