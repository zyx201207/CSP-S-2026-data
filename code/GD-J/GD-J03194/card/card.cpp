#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn],n,m,vis[maxn],su[maxn];
vector<int>vec[maxn];
set<int>se;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec[a[i]].push_back(i);
		se.insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				for(int r=vis[a[j]];r<j;r++)vis[a[r]]=0;
			}
			vis[a[j]]=j;
		}
		for(int j=1;j<=m;j++)if(vis[j]!=0)su[j]++;
	}
	for(int i=1;i<=m;i++)cout<<su[i]<<' ';
	return 0;
}
