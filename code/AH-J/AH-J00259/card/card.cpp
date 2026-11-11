#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int ans[N];
stack<int> q;
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(q.top()!=a[j]){
					vis[q.top()]=0;
					q.pop();
				}
			}
			else{
				vis[a[j]]=1;
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			vis[q.top()]=0;
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	puts("");
}
