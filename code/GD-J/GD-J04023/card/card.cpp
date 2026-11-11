#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
bool vis[300001];
int ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<int> po;
	vector<int> d;
	int n,m,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		po.push(c);
		d.push_back(c);
	}
	for(int i=1;i<=n;i++){
		vector<int>table;
		for(int j=i;j<=n;j++){
			if(vis[po.front()]==false){
				vis[po.front()]=true;
				table.push_back(po.front());
				po.pop();
			}else{
				bool flag=false; 
				for(int j=1;j<=table.size();j++){
					if(table[j]==po.front()){
						flag=true;
					}
					if(flag){
						vis[table[j]]=false;
						table[j]==po.front();
					}
				}
				vis[po.front()]=true;
				po.pop();
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
} 
