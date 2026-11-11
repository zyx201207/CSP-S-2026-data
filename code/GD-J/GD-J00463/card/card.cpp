#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
int n,m,a[N+10],vis[N+10],b[N+10];
stack<int> sd;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		memset(vis,0,sizeof vis);
		while(!sd.empty()) sd.pop();
		for(int j=i;j<=n;j++) {
			vis[a[j]]++;
			if(vis[a[j]]>1) {
				while(!sd.empty()) {
					int u=sd.top();
					sd.pop();
					vis[u]--;
					if(u==a[j]) break;
				}
			}
			sd.push(a[j]);
		}
		for(int j=1;j<=m;j++) {
			if(vis[j]>0) b[j]++;
		}
	} 
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";

	return 0; 
}
