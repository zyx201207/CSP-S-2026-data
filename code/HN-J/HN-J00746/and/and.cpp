#include<bits/stdc++.h>
using namespace std;
int n,m,a[10050],maxx=-10050;
void bfs(int x,int r){
	if(x==m){
		maxx=max(maxx,r);
		return;
	}
	bfs(x+1,r&a[x+1]);
	bfs(x,r);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	} 
	bfs(1,a[1]);
	cout <<maxx;
	return 0;
}
