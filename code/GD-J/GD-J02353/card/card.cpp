#include<iostream>
#include<queue>
#include<set>
using namespace std;
queue<int> q;
set<int> s;
int a[500100];
int vis[200100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=0;
	while(x<n){
		for(int i=x+1;i<=n;i++){
			if(s.count(a[i])){
				while(!q.empty()){
					q.pop();
				}
			}
			q.push(a[i]);
			s.insert(a[i]);
		}
		while(!q.empty()){
			int tmp=q.front();
			vis[tmp]++;
			q.pop();
		}
		for(auto y:s){
			s.erase(y);
		}
		x++;
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
} 
