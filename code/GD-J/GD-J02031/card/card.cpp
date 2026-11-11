#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
struct vis{
	bool is;
	int l;
}vis[300005];
int ans[500005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		vis[i].is =false;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		for(int i=j;i<=n;i++){
			q.push(a[j]);
			if(vis[a[i]].is==false){
				vis[a[i]].is =true;
				j++;
			}
			else if(vis[a[i]].is ==true){
				j=vis[a[i]].l ;
			}
		}
		while(!q.empty()){
			int o=q.front();
			q.pop();
			ans[o]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
