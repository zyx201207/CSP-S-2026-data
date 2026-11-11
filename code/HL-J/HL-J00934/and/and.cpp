#include<bits/stdc++.h>
using namespace std;
int n,a[200009],book[200009],maxx=-99999999,m;
void dfs(int x,int step){

	if(step==m){
		maxx=max(maxx,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			dfs(x&a[i],step+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		book[i]=1;
		dfs(a[i],1);
		book[i]=0;
	}
	cout<<maxx;
	return 0;
}