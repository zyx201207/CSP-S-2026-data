#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int mx;
void dfs(int i,int k,int g){
	if(m==g){
		mx=max(k,mx);
		return;
	}
	if(i>n+1||n-i+1<m-g) return;
	dfs(i+1,k,g);
	dfs(i+1,k&a[i],g+1);	
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,pow(2,21)-1,0);
		cout<<mx;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[1];
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else if(n==m){
		int o=a[1];
		for(int i=2;i<=n;i++) o=o&a[i];
		cout<<o;
	}else{
		sort(a+1,a+n+1);
		int o=a[1];
		for(int i=2;i<=m;i++) o=o&a[i];
		cout<<o; 
	}
	return 0;
} 

