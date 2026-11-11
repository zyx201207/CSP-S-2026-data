#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],b[200005],cnt,ans,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f=0;
	for(int i=1;i<=n;i++)vis[i]=1;
	for(int j=30;j>=0;j--){
		int s=0;
		for(int k=1;k<=n;k++){
			if(vis[k]&&(a[k]&(1<<j)))s++;
		}
		if(s<m)continue;
		ans|=(1<<j);
		for(int k=1;k<=n;k++)b[k]=0;
		for(int k=1;k<=n;k++){
			if(vis[k]&&(a[k]&(1<<j)))b[k]=1;
		}
		for(int k=1;k<=n;k++)vis[k]=b[k];
	}
	cout<<ans;
	return 0;
} 

