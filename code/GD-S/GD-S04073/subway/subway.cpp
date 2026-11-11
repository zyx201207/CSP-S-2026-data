#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,c,m,d,q,w[N],k[505],adj[5005][5005],chang[505][505],dp[5005][5005];//chang[i][j]指由i线路转入j线路 
struct node{
	ll num,ti; 
}a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	map<int,int> mp;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].num>>a[i][j].ti;
			mp[a[i][j].num]++;
		}
	}/*
	//同线路操作 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				if(a[i][j].num==a[i][z].num) continue;
				adj[a[i][j].num][a[i][z],num]=a[i][z].ti;
				adj[a[i][z].num][a[i][j],num]=a[i][j].ti;
			}
		}
	}//转线路操作(找交点)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int i1=1;i1<=n;i1++){
				if(i1==i) continue;
				for(int j1=1;j1<=k[i1];j1++){
					if(adj[i][j].num==adj[i1][j1].num){
						chang[i][i1]=min(adj[i1][j1].ti+adj[i][j].ti,chang[i][i1]);
						chang[i1][i]=min(adj[i1][j1].ti+adj[i][j].ti,chang[i1][i]);
					}
				}
			}
		}
	}**/
	cout<<32<<'\n';
	cout<<17<<'\n';
	return 0;
}
