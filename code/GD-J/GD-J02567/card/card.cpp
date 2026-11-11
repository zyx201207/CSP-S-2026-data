#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010];
bool f[300010];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0)q.push(a[j]),f[a[j]]=1;
			else{
				while(q.top()!=a[j]){
					f[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
		memset(f,0,sizeof(f));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
