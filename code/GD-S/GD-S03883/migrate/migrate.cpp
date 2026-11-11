#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=1e18;
int c,t,n,a[N],s;
int cnt_0[5010][5010],dis_0[5010][5010];
queue<int> q;
void solve(int st){
	q.push(st);
	dis_0[st][st]=1;
	cnt_0[st][st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[u]>s)break;
			if(dis_0[st][u]+1<dis_0[st][v]){
				dis_0[st][v]=dis_0[st][u]+1;
				q.push(v);
			}
			if(dis_0[st][u]+1==dis_0[st][v])cnt_0[st][v]+=cnt_0[st][u];
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>s;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cnt_0[i][j]=0,dis_0[i][j]=INF;
		}
		for(int st=1;st<=n;st++)solve(st);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt_0[i][j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}	
	return 0;
}
