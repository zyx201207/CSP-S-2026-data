#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx;
void dfs(int i,long long he,int x,int f){
	if(x==m){
		if(he>mx)mx=he;
		return;
	}
	if(i==n)return;
	dfs(i+1,he,x,f);
	if(i!=f)dfs(i+1,he&a[i],x+1,f);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(0,a[i],1,i);
	}
	cout<<mx;
	return 0;
}
