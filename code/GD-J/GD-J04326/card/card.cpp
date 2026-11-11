#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],f[N],ans[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int>q;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(true){
					int x=q.back();
					q.pop_back();
					vis[x]--;
					if(x==a[j]) break;
				}
			}
			vis[a[j]]++;
			q.push_back(a[j]);
		}
		while(!q.empty()){
			int x=q.front();
			ans[x]++;
			vis[x]--;
			q.pop_front();
		}
	} 
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
