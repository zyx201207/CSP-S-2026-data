#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MAXN=5e3+5;
ll dis[MAXN];//连通块里面起点到的距离
ll x[MAXN];
ll dp[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dis[i]=LLONG_MAX;
		}
		for(int i=1;i<=n;i++){
			if(dis[i]==LLONG_MAX)dis[i]=0;
			for(int j=i+1;x[j]-x[i]<=d&&j<=n;j++){
				dis[j]=min(dis[j],dis[i]+1);
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<dis[i]<<" ";
//		}
//		cout<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=i-1;j>=1&&dis[j]+1==dis[i];j--){
				cnt++;
			}
			if(cnt==2)ans++;
	 	}
		cout<<ans<<'\n';
	}
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
