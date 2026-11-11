#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],vis[N],ans[N];
stack<int>z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(z.top()!=a[j]){
					vis[z.top()]=0;
					z.pop();
				}
			}
			else{
				z.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(z.size()){
			ans[z.top()]++;
			vis[z.top()]=0;
			z.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
