#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],maxx=0,qq=0,b[200001];

void dfs(int w,int ww){
	if(ww==m){
		
		maxx=max(maxx,qq);
	
		return;
	}
	for(int i=w+1;i<=n;i++){
		long long www=qq;
		if(ww==0){
			qq=a[i];
		}else{
			qq=qq&a[i];
		}
		b[ww+1]=a[i];
		dfs(i,ww+1);
		qq=www;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxx;
	return 0;
}
