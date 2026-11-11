#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,c,t;
long long d,x[maxn],dis[maxn],cnt[maxn];
int check(int u)
{
	int ans=0;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[u]=0;cnt[u]=1;
	for(int i=u+1;i<=n;i++){
		for(int j=i-1;j>=u;j--){
			if(x[i]-x[j]>d)break;
			if(dis[i]>dis[j]+1){
				dis[i]=dis[j]+1;
				cnt[i]=cnt[j];
			}
			else if(dis[i]==dis[j]+1)cnt[i]+=cnt[j];
		}
		if(cnt[i]==2)ans++;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;int ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)ans+=check(i);
		cout<<ans<<"\n";
	}
	return 0;
}
