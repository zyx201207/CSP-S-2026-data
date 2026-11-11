#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int minn=INT_MIN;
void dfs(int x,int cnt){
	if(x==m){
		minn=max(minn,cnt);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(x==1){
			cnt=a[i];
		}
		dfs(x+1,cnt&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,a[1]);
	cout<<minn;
	return 0;
}
//5 3
//31 3 1 15 7

