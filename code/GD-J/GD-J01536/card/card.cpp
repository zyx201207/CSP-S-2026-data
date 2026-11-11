#include<bits/stdc++.h>
using namespace std;
const int Q=5*1e5+5;
int n,m,x;
queue<int> vis;
vector<int> table;
int ans[Q],a[Q];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>x;
		a[i]=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) vis.push(a[i]);
		while(!vis.empty()==true){
			int s=table.size();
			int q=lower_bound(table,table+s,vis.front())-table;
			if(table[q]==vis.front){
				for(int j=q;j<=s;j++){
					table[j]=0;
				}
			}
			table.push(vis.front()); 
		   
		    vis.pop();
		}
		vis.clear();table.clear;
	}
	return 0;
}
