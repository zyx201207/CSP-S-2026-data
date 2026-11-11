#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=501,M=1e3+1;
int c,n,m,d,q;
ll w[M],t[M][21],num[N],numn[M],mp[M][M],ans;
bool vis[M][21],a[N][M];
ll s,e;
ll dfs(ll node,ll line,ll sums){
	if(node>m or line>n){
		return INT_MAX;
//		cout<<1;
	}
	cout<<line<<" "<<node<<sums<<endl;
	sums+=t[node][line];
	if(node==e){
//		cout<<1;
		return sums+w[e];
	}
	else{
//		cout<<2;
		ll cnt=INT_MAX;
		for(int i=1;i<=num[line];i++){
//			cout<<3;
			if(numn[a[line][i]]>=1){
			 	for(int j=1;j<=numn[a[line][i]];j++){
//			 		cout<<4;
			 		cnt=min(cnt,dfs(node,vis[node][j],sums+t[node][j]));
				}
			}
			else{
				cnt=min(cnt,dfs(a[line][i],line,sums));
			}
		}
		return cnt;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int node;
			cin>>node;
			cin>>t[node][i];
			vis[node][j]=i;
			numn[node]++;
			num[i]++;
			a[i][j]=node;
		}
	}
	for(int i=1;i<=q;i++){
		ans=INT_MAX;
		cin>>s>>e;
		for(int i=1;i<=20;i++){
			if(vis[s][i]){
				ans=min(ans,dfs(s,i,w[s]));
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
