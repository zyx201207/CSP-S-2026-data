#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=2e5+5;
int a[N];
int vis[N];
int ans_[N];
int ans=0;

bool cmp(int x,int y){
	return x>y;
}

void dfs(int k){
	if(k>m){
		int sum=ans_[1];
		for(int i=2;i<=m;i++){
			sum&=ans_[i];
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		ans_[k]=a[i];
		dfs(k+1);
		vis[i]=0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<=2000) dfs(1);
	else{
		sort(a+1,a+n+1,cmp);
		ans=a[m];
	}
	
	cout<<ans;
	return 0;
}

