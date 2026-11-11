#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			vis[i]=a[i];
			vis[i]=max(vis[i],vis[i]&vis[j]);
		}
	}
	cout<<vis[n];
	return 0;
}
