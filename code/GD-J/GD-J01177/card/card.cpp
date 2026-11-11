#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		bool vis[200005]={};
		deque<int>q;
		q.push_back(a[i]);
		vis[a[i]]=1;
		for(int j=i+1;j<n;j++){
			if(vis[a[j]]){
				while(q.back()!=a[j]){
					vis[q.back()]=0;
					q.pop_back();
				}
			}else{
				q.push_back(a[j]);
				vis[a[j]]=true;
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
