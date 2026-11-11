#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500001],vis[500001],vis_f[500001];
stack<long long> k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis_f[a[j]]==0){
				k.push(a[j]);
				vis_f[a[j]]=1;
			}
			else
				while(k.top()!=a[j])k.pop();			
		}
		while(!k.empty()){
			vis[k.top()]++;
			k.pop();
		}
		for(int v=1;v<=n;v++)vis_f[v]=0;			
	}
	for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
	cout<<"\n";
	return 0;
}
