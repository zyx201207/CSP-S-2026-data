#include<bits/stdc++.h>
using namespace std;

int n,m;
int best=-1;
long long a[200005]={0};

void dfs(int x,int b,int ans){
	if(b==m){
		if(ans>best){
			best=ans;
		}
		return;
	}
	for(int i=1;i<=n-m+1;i++){
		if(b==0){
			dfs(i,b+1,a[i]);
		}else{
			dfs(i,b+1,ans&a[i]);
		}
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
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<best;
	return 0;
}
