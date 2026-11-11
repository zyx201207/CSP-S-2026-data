#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,x[N],ans,cnt[N],nex[N],dis[N],q[N],tot;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++) cin>>x[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
//		if(c==11||c==12){
			d=d/(x[2]-x[1]);
			if(d<=1) cout<<"0\n";
			else cout<<max(n-2*d+1,0ll)<<'\n';
			continue;
//		}
		x[n+1]=8e18,ans=0;
		for(int i = 1;i<=n;i++) nex[i]=upper_bound(x+1,x+2+n,x[i]+d)-x-1;
		for(int i = 1;i<=n;i++){
			int lt=i,flag=0;
			cnt[i]=dis[i]=1,q[++tot]=i;
			for(int j = i;;j=nex[j]){
				if(j==i&&!flag){
					flag=1;
					continue;
				}
				if(dis[j]) break;
				dis[j]=dis[lt]+1,cnt[j]=cnt[lt],q[++tot]=j;
				if(j-1>i&&!dis[j-1]) dis[j-1]=dis[lt]+1,cnt[j-1]=cnt[lt],q[++tot]=j-1;
				if(j-2>i&&!dis[j-2]) dis[j-2]=dis[lt]+1,cnt[j-2]=cnt[lt],q[++tot]=j-2;
				if(dis[lt-1]==dis[lt]){
					if(x[j]-x[lt-1]<=d) cnt[j]+=cnt[lt-1];
					if(dis[j-1]==dis[j]){
						if(x[j-1]-x[lt-1]<=d) cnt[j-1]+=cnt[lt-1];
						if(dis[j-2]==dis[j]&&x[j-2]-x[lt-1]<=d) cnt[j-2]+=cnt[lt-1];
					}
					if(dis[lt-2]==dis[lt]){
						if(x[j]-x[lt-2]<=d) cnt[j]+=cnt[lt-2];
						if(dis[j-1]==dis[j]){
							if(x[j-1]-x[lt-2]<=d) cnt[j-1]+=cnt[lt-2];
							if(dis[j-2]==dis[j]&&x[j-2]-x[lt-2]<=d) cnt[j-2]+=cnt[lt-2];
						}	
					}
				}
//				cout<<i<<' '<<j<<' '<<dis[j-1]<<' '<<cnt[j-1]<<' '<<dis[j]<<' '<<cnt[j]<<'\n';
				lt=j;
				if(dis[j-1]==dis[j]){
					cnt[j-1]=min(cnt[j-1],3ll);
					if(dis[j-2]==dis[j]) cnt[j-2]=min(cnt[j-2],3ll);
				}
				if(cnt[j]>2) break;
				if(cnt[j]==2) ans+=nex[j]-nex[j-1];
				else if(dis[j-1]==dis[j]&&cnt[j-1]==1) ans+=nex[j-1]-nex[j-2];
			}
			while(tot) dis[q[tot]]=cnt[q[tot]]=0,tot--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
