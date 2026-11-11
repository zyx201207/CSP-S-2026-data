#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int a[maxn],cnt[maxn];
int vis[maxn];
vector<int>G{}; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//É¾×¢ÊÍ
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>().swap(G);
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				while(G.back()!=a[j]){
					vis[G.back()]-=1;
					G.pop_back();
				}
			}else G.emplace_back(a[j]),vis[a[j]]+=1;
		}
		for(int j=1;j<=m;j++)cnt[j]+=vis[j];
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";cout<<'\n';
	return 0;
} 
/*
3 1 2 1 3 2 3 1 2 1
 
*/ 
