#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mx;
bool vis[200010];
void dfs(long long id,int cen){
	if(cen==m)mx=max(mx,id);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(id&=a[i],cen+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				mx=max(mx,a[i]|a[j]);
			}
		}cout<<mx;
	}else if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx&=a[i];
		}cout<<mx;
	}else{
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(a[i],0);
			vis[i]=0;
		}cout<<mx;
	}
	return 0;
}
