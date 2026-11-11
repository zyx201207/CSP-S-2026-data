#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans[100005],dis=1;
queue <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int aa=n;
	while(aa--){
		int vis[100005];
		for (int i=dis;i<=n;i++){
			vis[a[i]]+=1;
			if (vis[a[i]]>1){
				 while(!q.empty()){
					 q.pop();
				}
				vis[a[i]]=1;
			}
			q.push(a[i]);
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop();
		}
		dis++;
		for (int i=1;i<=n;i++){
			vis[i]=0;
		}
	}
	for (int i=1;i<=m;i++){
		cout << ans[i]<<" ";
	}
}
