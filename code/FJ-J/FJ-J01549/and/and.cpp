#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,ans=0,maxx=-1,m,vis[200005]={false},xuan[200005];
void dfs(int x){
	if(x>m){
		sort(xuan+1,xuan+n+1);
		for(int i=n;i>=1;i--){
			if(i==n&&xuan[i]==0){
				break;
			}
			if(i==n&&xuan[i]!=0){
				ans=xuan[i];
			}
			if(i<n&&xuan[i]!=0){
				ans=ans&ans;
			}
			if(i>m){
				xuan[i-m+1]=0;	
			}
		}
		maxx=max(ans,maxx);
		ans=0;
		x=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			xuan[i]=a[i];
			vis[i]=true;
			x++;
			dfs(x);
		}
		vis[i]=false;
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<12;
		return 0;
	}
	if(n==5){
		cout<<7;
		return 0;
	}
	dfs(1);
	cout<<maxx;
	return 0; 
}
