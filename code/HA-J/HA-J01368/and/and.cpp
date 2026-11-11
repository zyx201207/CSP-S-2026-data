#include<bits/stdc++.h>
using namespace std;
int n,m,u,a[200010],b[40],d=-67;
bool pq(int a,int b){
	return a>b;
}
void dfs(int x,int y,int z){
	if(x>m||y<=d||z>n){
		return;
	}
	if(!x&&a[z]<(1<<u)){
		return;
	}
	if(x==m){
		d=max(d,y);
	}
	dfs(x+1,y&a[z],z+1);
	dfs(x,y,z+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]<(1<<j)){
				b[j]++;
				b[j]>1;
				u=max(u,j-1);
				break;
			}
		}
	}
	sort(a+1,a+n+1,pq);
	dfs(0,-1,1);
	cout<<d;
	return 0;
}
