#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int Max=-1;
int a[200005];
bool vis[200005];
void dfs(int d,int s,int step){
	if(step==m){
		Max=max(Max,d);
	}if(d<Max) return;
	for(int i=s;i<n;i++){
		if(vis[i]==0) dfs(d&a[i],i,step+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		cin>>a[0];
		ans=a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
	}else if(m==1){
		for(int i=0;i<n;i++){
			cin>>a[i];
			Max=max(Max,a[i]);
		}
		ans=Max;
	}else if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				Max=max(Max,a[i]&a[j]);
			}
		}
		ans=Max;
	}else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}for(int i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			dfs(a[i],i,1);
		}
		ans=Max;
	}
	cout<<ans;
	return 0;
}
