#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],g,ans,ans1,ans2,ans3;
void dfs(int x,int y,int z){
	if(x==n+1){
		if(y==m){
			ans=max(ans,z);
		}
	}else{
		dfs(x+1,y,z);
		if(y!=m)dfs(x+1,y+1,z&a[x]);
	}
}
void dfs1(int x,int y,int z){
	if(x==n+1){
		if(y==1){
			ans3=max(ans3,z);
		}
	}else{
		if(y==0)dfs(x+1,y+1,z);
		dfs(x+1,y,z&a[x]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			g=a[i];
		}else g&=a[i];
		ans1=max(a[i],ans1);
	}if(m==n)return cout<<g,0;
	if(n<=20){
		dfs(1,0,(1<<31)-1);
		return cout<<ans,0;
	}if(m==1){
		return cout<<ans1,0;
	}if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans2=max(ans2,a[i]&a[j]);
			}
		}return cout<<ans2,0;
	}
	if(m==n-1){
		dfs1(1,0,(1<<31)-1);
		return cout<<ans3,0;
	}
	cout<<0;
}
