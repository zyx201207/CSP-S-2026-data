#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N=5005;
ll c,t,n,d,x[N],l[N],r[N],nxt[N],cnt[N][2];
pii dp[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		if(n>5000)
		{
			ll ans=0;
			for(ll i=1;i<=n;i++)
			{
				cin>>x[i];
				cnt[i][0]=cnt[i][1]=0;
				l[i]=0;
			}
			for(ll i=1,j=1;i<=n;i++)
			{
				while((j<n)&&((x[j+1]-x[i])<=d)) j++;
				nxt[i]=j;
				if(!l[j]) l[j]=i;
				r[j]=i;
			}
			ans=0;
			ll cntt=1;
			for(ll i=1;i<=n;i++)
			{
				if(!l[i])
				{
					cntt++;
					continue;
				}
				cnt[i][0]=r[i]-l[i]+1;
				ll tmp=0;
				if(l[i]+1<i)
				{
					ll num=l[i]+1;
					if(l[num])
					{
						tmp=cnt[l[num]][0];
						if(l[i]+1<=r[i]) cnt[i][1]+=(r[num]-l[num]+1+tmp);
						else ans+=(r[num]-l[num]+1+tmp);
					}
				}
				ll tt=l[i];
				if(l[tt])
				{
					if(l[i]+1<=r[i]) cnt[i][1]+=(cnt[tt][1]-tmp);
					else cnt[i][1]+=cnt[tt][1],ans-=tmp;
					cnt[i][0]+=cnt[tt][0];
				}
				ans+=cntt*cnt[i][1];
				cntt=1;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		for(ll i=1,j=1;i<=n;i++)
		{
			while((j<n)&&((x[j+1]-x[i])<=d)) j++;
			nxt[i]=j;
		}
		int ans=0;
		for(int len=1;len<=n;len++)
		{
			for(int i=1,j=len;j<=n;i++,j++)
			{
				if(len==1)
				{
//					cout<<i<<" "<<j<<"fghfdgdhgshg\n";
					dp[i][j]=pii(1,1);
					continue;
				}
				int tmp=nxt[i];
//				cout<<i<<" -> "<<tmp<<"\n";
				if(tmp==i)
				{
					dp[tmp][j]=pii(0,0);
					continue;
				}
				if(tmp>=j)
				{
//					cout<<i<<" "<<j<<" dsagdgsafgsafsad\n";
					dp[i][j]=pii(1,1);
					continue;
				}
				if(dp[tmp][j].second==0)
				{
					dp[i][j]=pii(0,0);
					continue;
				}
				dp[i][j].first=dp[tmp][j].first+1;
				dp[i][j].second=dp[tmp][j].second+(((tmp-1>i)&&(dp[tmp-1][j].first==dp[tmp][j].first))?dp[tmp-1][j].second:0)+(((tmp-2>i)&&(dp[tmp-2][j].first==dp[tmp][j].first))?dp[tmp-2][j].second:0);
				dp[i][j].second=min((ll)3,dp[i][j].second);
//				cout<<i<<" "<<j<<" "<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";
//				cout<<ttttt<<"  ttttt\n";
//				cout<<"fsdafsadvgsfsdafav   "<<dp[tmp][j].second<<"   +    "<<((tmp-1>i)&&(dp[tmp-1][j].first==dp[tmp][j].first))<<" ? "<<dp[tmp-1][j].second<<" : "<<0<<"\n" ;
				if(dp[i][j].second==2) ans++;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i;j<=n;j++) cout<<i<<" "<<j<<" "<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";;
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
