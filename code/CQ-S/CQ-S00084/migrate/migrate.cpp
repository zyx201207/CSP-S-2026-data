#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,n,t,d,ans;
int dist[N],cnt[N],a[N];
queue<pair<int,int > > q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt[j]=0;
				dist[j]=N;
			}dist[i]=0;
			q.push(make_pair(i,0));
			while(!q.empty()){
				int x=q.front().first;
				int w=q.front().second;
				q.pop();
				for(int j=x+1;j<=n;j++){
					if(a[j]-a[x]>d) break;
					if(w+1<dist[j]){
						cnt[j]=1;
						dist[j]=w+1;
						q.push(make_pair(j,w+1));
					}
					else if(w+1==dist[j]&&cnt[j]<3){
						cnt[j]++;
						q.push(make_pair(j,w+1));
					}
				}
			}
			for(int j=i;j<=n;j++) if(cnt[j]==2) ans++;
//			for(int j=i;j<=n;j++){
//				cout<<dist[j]<<" ";
//			}
//			cout<<"\n";
//			for(int j=i;j<=n;j++){
//				cout<<cnt[j]<<" ";
//			}
//			cout<<"\n";
		}cout<<ans<<"\n";
	}
	return 0;
}
