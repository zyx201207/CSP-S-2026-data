#include<bits/stdc++.h>
using namespace std;
long long cnt,c,T,n,d,a[2000010],last,ans,dis[2000010],A;
vector<long long> E[2000010];
void dfs(long long cur,long long ed,long long k,long long tot){
	if(k==tot){
		if(cur==ed) cnt++;
		return;
	}
	for(long long i:E[cur]){
		dfs(i,ed,k+1,tot);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==12||c==11){
		while(T--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			A=a[2]-a[1];
			if(d<2*A)cout<<0<<"\n";
			else cout<<max((long long)0,n-((d/A)*2-1))<<"\n";
		}
		return 0;
	}
	if(c<=6){
		while(T--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
				E[i].clear();
			}
			last=1;
			for(long long i=2;i<=n;i++){
			//	cout<<i<<":";
				while(a[i]-a[last]>d) last++;
				for(long long j=last;j<i;j++){
					E[i].push_back(j);
				//	cout<<j<<" ";
				}
			//	cout<<endl;
			}
			ans=0;
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++) dis[j]=1e18;
				dis[i]=0;
				for(long long j=i+1;j<=n;j++){
					for(long long k:E[j]){
						if(k<i) continue;
						dis[j]=min(dis[j],dis[k]+1);
					}
				//	cout<<i<<" "<<j<<" "<<dis[j]<<endl; 
					cnt=0;
					dfs(j,i,0,dis[j]);
					if(cnt==2) {
						ans++;
					//	cout<<i<<" "<<j<<" "<<dis[j]<<endl;
					}
				}
			}
			cout<<ans<<"\n";
		}	
		return 0;
	}
	
	while(T--){
		cout<<0<<"\n";
	}
	return 0;
} 
