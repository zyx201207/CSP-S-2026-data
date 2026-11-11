#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,mx=INT_MIN;
int a[N];
bool vis[N];
void dfs(int x,int u,int step){
	if(step>m){
		mx=max(mx,x);
		//cout<<"mx:"<<mx<<'\n';
		return;
	}
	//cout<<"x:"<<x<<" step:"<<step<<'\n'; 
	for(int i=step+1;i<=n;i++){
		if(u!=i) dfs(x&a[i],i,step+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++) mx&=a[i];
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(a[i],i,1);//cout<<"mx:"<<mx<<' '<<a[i]<<'\n';
	cout<<mx;
	return 0;
} 
