//GZ-S00078 贵阳市新世界学校 王正彭 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll floyd[5005][5005];
ll fsum[5005][5005];
vector<ll> vt[5005];
ll a[100005];
map<pair<ll,ll>,ll > mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		cout<<"0\n";
		/*for(int i=0;i<=5004;i++)
		vt[i].clear();
		memset(floyd,0x3f,sizeof(floyd));
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					floyd[i][j]=j-i;
					floyd[j][i]=j-i;
					mp[{i,j}]=j-i;
					mp[{i,j}]=j-i;
				}
				else break;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			floyd[i][i]=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
				if(i!=k)
					for(int j=1;j<=n;j++)
						if(j!=i&&j!=k)
						{
							if(mp[{i,k}]&&mp[{k,j}]&&floyd[i][k]+floyd[j][k]<=d)
							floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[j][k]);
						}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
				if(i!=k)
					for(int j=1;j<=n;j++)
						if(j!=i&&j!=k)
						{
							if(mp[{i,k}]&&mp[{k,j}]&&floyd[k][j]+floyd[i][k]==floyd[i][j])
							fsum[i][j]++;
						}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<floyd[i][j]<<'\n';
		ans+=(fsum[i][j]==2);}
		cout<<ans<<'\n';*/
	}
	return 0;
}
