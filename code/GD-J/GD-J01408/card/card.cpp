#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
bool vis[300005]={0};
int a[500005];
deque <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(vis[a[i]]){
				while(q.back()!=a[i]){
					vis[q.back()]=0;
					q.pop_back();
				}
			}else{
				q.push_back(a[i]);
				vis[a[i]]=1;
			}
		}
		while(!q.empty()){
			vis[q.back()]=0;
		    ans[q.back()]++;
		    q.pop_back(); 
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		return 0;
}
