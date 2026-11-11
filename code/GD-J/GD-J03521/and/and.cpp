#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn=0,g;
void dfs(int x,int s,int y){
	if(x==m){
		g=max(y,g);
	}
	for(int i=s+1;i<=n;i++){
		dfs(x+1,i,y&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==n-1){
		int x=a[2];
		for(int i=3;i<=n-1;i++){
			x&=a[i];
		}
		cout<<max(x&a[1],x&a[n]);
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxnn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxnn=max(a[i]&a[j],maxnn);
			}
		}
		cout<<maxnn;
		return 0;
	}
	if(n<=200){
		for(int i=1;i<=n-m+1;i++){
			dfs(1,i,a[i]);
		}
		cout<<g;
		return 0;
	}
	sort(a,a+n);
	cout<<a[n-m+1];
	return 0;
}
