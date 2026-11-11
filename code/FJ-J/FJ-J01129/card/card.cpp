#include <bits/stdc++.h>
using namespace std;
int n,m,vis[300010],a[500010],ans[300010],x,y;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

