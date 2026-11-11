#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,x,a[500010],m,vis[500010],d[500010],f[500010],mx,k,c1,c2;
void dfs(int x,int num){
//+	cout<<x<<" "<<num<<endl;
	if(x==m){
		mx=max(mx,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,(num&a[i]));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>2000){
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--) ans=(ans&a[i]);
		cout<<ans;
		exit(0);
	}
	for(int i=1;i<=n;i++) vis[i]=1,dfs(1,a[i]),vis[i]=0;
	cout<<mx;
}
