#include <bits/stdc++.h>
#define int long long
using namespace std;
int ccc,t,n,d,a[2000010],dis[2000010],cc[2000010];
vector<int> e[2000010];
void dfs(int id,int fa){
//	cout<<"Now:"<<id<<" "<<fa<<endl;
//	for(int i=0;i<e[id].size();i++) cout<<e[id][i]<<endl;
	for(int i=0;i<e[id].size();i++){
//		cout<<"GO:"<<id<<" "<<e[id][i]<<endl;
		if(dis[e[id][i]]>dis[id]+1) dis[e[id][i]]=dis[id]+1,cc[e[id][i]]=1,dfs(e[id][i],id);
		else if(dis[e[id][i]]==dis[id]+1) cc[e[id][i]]++,dfs(e[id][i],id);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>d;
		if(n==1) cout<<0<<'\n';
		else if(ccc==0){
			for(int i=1;i<=n;i++) cin>>a[i];
			int op=a[2]-a[1],nm=d/op;
//			cout<<n<<" "<<nm<<endl;
			if(nm<=1) cout<<0<<'\n';
			else cout<<max(0LL,n-2*(nm-1)-1)<<'\n';
//			else cout<<0<<'\n';
		}
		else if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++) e[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) e[i].push_back(j);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dis[j]=1e18,cc[j]=0;
				dis[i]=0,cc[i]=1;
				dfs(i,0);
//				for(int j=i;j<=n;j++) cout<<cc[j]<<" ";
//				cout<<endl;
				for(int j=i+1;j<=n;j++){
					if(cc[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
