#include <bits/stdc++.h>
using namespace std;
int num[300010],ans[300010];
int n,m;
int d[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w"stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	stack<int> q;
	for(int i=1;i<=n;i++){
		for(int x=1;x<=m;x++) num[x]=0;
		for(int j=i;j<=n;j++){
			if(num[d[j]]==0){
				q.push(d[j]);
				num[d[j]]++;
			}else if(num[d[j]]==1){
				while(q.top()!=d[j]){
					q.pop();
				}q.pop();
				q.push(d[j]);
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
