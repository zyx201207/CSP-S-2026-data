#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		ans[i]=ans[i-1]+vis[i];
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
