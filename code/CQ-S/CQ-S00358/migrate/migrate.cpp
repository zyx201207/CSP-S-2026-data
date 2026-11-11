#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+10;
ll a[MAXN];
int ct[10][10];
int n;
ll d;
vector<int> ch;
int mn[10][10];
void dfs(int step)
{
	if(step>n)
	{
		int lc=ch.size();
		if(lc<2) return;
		bool flag=false; 
		for(int i=1;i<lc;i++)
		{
			if(a[ch[i]]-a[ch[i-1]]>d)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			if(lc<mn[ch[0]][ch[lc-1]])
			{
				mn[ch[0]][ch[lc-1]]=lc;
				ct[ch[0]][ch[lc-1]]=1;
			}
			else if(lc==mn[ch[0]][ch[lc-1]]) ct[ch[0]][ch[lc-1]]++;
		}
		return;
	}
	dfs(step+1);
	ch.push_back(step);
	dfs(step+1);
	ch.pop_back();
}
int dp[310][310];//the num of lands
int re[310][310];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==1 || c==2)
	{
		while(t--)
		{
			memset(ct,0,sizeof(ct));
			memset(mn,0x3f,sizeof(mn));
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			dfs(1);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(ct[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	if(c>=11 && c<=12)
	{
		while(t--)
		{
			int n;
			ll d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[2]-a[1]<=d) cout<<n-2<<endl;
			else cout<<0<<endl;
		}
		return 0;
	}
	if(c>=3 && c<=6)
	{
//		cout<<"sdfs"<<endl;
		while(t--)
		{
			int n;
			ll d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			memset(dp,0x3f,sizeof(dp));
			memset(re,0,sizeof(re));
			for(int i=1;i<=n;i++)
			{
				dp[i][i]=0;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d) dp[i][j]=1/*,cout<<"ii="<<i<<" jj="<<j<<endl*/;
				 } 
			}
			for(int len=3;len<=n;len++)
			{
				for(int i=1;i+len-1<=n;i++)
				{
					int j=i+len-1;
					for(int k=i+1;k<j;k++)
					{
						if(dp[i][k]+dp[k][j]<dp[i][j])
						{
							dp[i][j]=dp[i][k]+dp[k][j];
							re[i][j]=1;
//							cout<<"ii="<<i<<" j="<<j<<" k="<<k<<" dp="<<dp[i][j]<<endl;
						}
						else if(dp[i][k]+dp[k][j]==dp[i][j])
						{
							re[i][j]++;
//							cout<<"i="<<i<<" j="<<j<<" k="<<k<<" dp="<<dp[i][j]<<endl;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(re[i][j]==(dp[i][j]-1)*2 && re[i][j]!=0)
					{
//						cout<<"ansi="<<i<<" j="<<j<<" re="<<re[i][j]<<endl;
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		
		return 0;
	}
	return 0;
}

