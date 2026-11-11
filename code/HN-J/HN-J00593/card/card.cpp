#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int t[N];
bool vis[N];
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1) memset(vis,0,sizeof(vis));
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++) if(vis[j]==1) t[j]++;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
