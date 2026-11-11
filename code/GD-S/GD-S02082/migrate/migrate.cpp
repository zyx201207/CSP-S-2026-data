#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+1; 
int n,d;
int vis[N];
int dis[N];
deque<pair<int,int>> q;
int x[N],nex[N];
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			dis[i]=0;
			vis[i]=0;
		} 
		int ans=0;
		scanf("%lld%lld",&n,&d);
		int j=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			while(x[i]-x[j]>d) j++;
			nex[i]=j;
		}
		for(int i=1;i<=n;i++){	
			vis[i]=vis[nex[i]]+1;
			if(i-nex[i]==2&&i-1-nex[i-1]==2){
				dis[i]=1;
				ans++;
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
