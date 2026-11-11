#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],maxx=-1,ans;
void dfs(int t,int noans,int nowi){
	if(t==m+1){
		if(noans>maxx)maxx=noans;
		return;
	}
	for(int i=nowi;i<=n;i++){
		if(t==1)dfs(t+1,a[i],i+1);
		else dfs(t+1,(noans&a[i]),i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==m){
		maxx=a[1];
		for(int i=1;i<=n;i++)maxx=(maxx&a[i]);
	}
	else dfs(1,0,1);
	cout << maxx;
	return 0;
}
