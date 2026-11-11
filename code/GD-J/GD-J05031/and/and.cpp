#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
bool cmp2(int x,int y){
	return x>y;
}
void dfs(int x,int s){
	if(x>m){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,s&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	bool ok1=1,ok2=1;
	double tmp=log2(n);
	if((int)tmp!=tmp) ok2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ok1){
			tmp=log2(a[i]+1);
			if((int)tmp!=tmp) ok1=0;
		}
		if(ok2){
			if(a[i]!=i-1) ok2=0;
		}
	}
	if(m==n){
		ans=(1<<30)-1;
		for(int i=1;i<=n;i++) ans&=a[i];
		return cout<<ans,0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		return cout<<ans,0;
	}
	if(ok1){
		ans=(1<<30)-1;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=m;i++) ans&=a[i];
		return cout<<ans,0;
	}
	if(ok2){
		ans=(1<<30)-1;
		for(int i=n;i>=n-m+1;i--) ans&=a[i];
		return cout<<ans,0; 
	}
	dfs(1,(1<<30)-1);
	cout<<ans;
	return 0;
}

