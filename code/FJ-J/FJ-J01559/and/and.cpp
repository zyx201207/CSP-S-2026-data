#include<bits/stdc++.h>
using namespace std;
long long maxn=0;
bool vis[200005];
long long arr[200005];
int n,m;
bool cmp(int a,int b){
	return a>=b;
}
void bfs(int ci,long long dan,int ii){
	if(ci==m){
		maxn=max(dan,maxn);
	}
	else{
		for(int i=ii;i<=n;++i){
			if(!vis[i]){
				dan=dan&arr[i];
				vis[i]=true;
				bfs(ci+1,dan,i+1);
				vis[i]=false;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n-m+1;++i){
		vis[i]=true;
		bfs(1,arr[i],i);
		vis[i]=false;
	}
	cout<<maxn;
}
