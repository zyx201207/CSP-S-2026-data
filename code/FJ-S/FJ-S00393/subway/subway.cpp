/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
//T1T2一点都没思路气哭了 只能4题都骗了 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
	int v,x;
};
vector<node> V[500005];
int w[500005];
int a[505][50005],t[505][50005],k[505];
bool vis[505];
int S,T;
long long cnt,ans;
void dfs(int now,int xl){
	if(now==T){
		cnt+=w[T];
		cnt+=t[xl][now];
//		cout<<ans<<" "<<cnt<<endl; 
		ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<V[now].size();i++){
		int v=V[now][i].v,x=V[now][i].x;
//		cout<<now<<" "<<xl<<" "<<v<<" "<<x<<endl;
		if(v==now&&x==xl){
			continue;
		}
		if(vis[x]){
			continue;
		}
//		cout<<now<<" "<<xl<<" "<<v<<" "<<x<<endl;
		if(x==xl){
			vis[x]=1;
			dfs(v,x);
//			vis[x]=0;
		}else if(v==now){
//			cout<<t[xl][now]<<" "<<t[x][v]<<endl;
			cnt+=t[xl][now]+t[x][v];
//			cout<<cnt<<endl;
			dfs(v,x);
//			cnt-=(t[xl][now]+t[x][v]);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			V[a[i][j]].push_back({a[i][j],i});
			if(j!=1){
				V[a[i][j]].push_back({a[i][j-1],i});
				V[a[i][j-1]].push_back({a[i][j],i});
				
			}
		}
	}
//	for(int i=1;i<=6;i++){
//		for(int j=0;j<V[i].size();j++){
//			cout<<V[i][j].v<<" "<<V[i][j].x<<endl;
//		}
//		cout<<endl;
//	}
	while(q--){
		cin>>S>>T;
		ans=1e18;
		for(int i=0;i<V[S].size();i++){
			if(V[S][i].v==S){
//				cout<<"======="<<endl;
				memset(vis,0,sizeof(vis));
				cnt=w[S]+t[V[S][i].x][S];
				dfs(S,V[S][i].x);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
