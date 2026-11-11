#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int ans[M],vis[M];
stack<int> u;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!u.empty()) u.pop();
		for(int j=i;j<=n;j++){
			while(vis[a[j]]){
				vis[u.top()]--;
				u.pop();
			}
			u.push(a[j]);
			vis[a[j]]++;
		}
		for(int j=i;j<=n;j++) if(vis[a[j]]) ans[a[j]]++,vis[a[j]]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
