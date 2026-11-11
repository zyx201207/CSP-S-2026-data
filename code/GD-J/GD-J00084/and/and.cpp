#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005],b[200005]={0},ttt=0;
int yue(int x,int y){
	if(x==0) return y;
	if(y==0) return x; 
	int ans=0,n=1;
	int maxx=max(x,y);
	while(max(x,y)>0){
		if(x%2==y%2 && x%2==1 && y%2==1){
			ans+=n;
		}
		x/=2;
		y/=2;
		n*=2;
	}
	return ans;
} 
void dfs(int k,int we,int ans){
	if(b[k]==1) return;
	if(we==m){
		ttt=max(ttt,ans);
	}
	if(k>n) return;
	dfs(k+1,we,ans);
	b[k]=1;
	dfs(k+1,we+1,yue(ans,a[k]));
	b[k]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0,num=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxx=max(a[i],maxx);
		num=yue(num,a[i]);
	}
	if(m==1){
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		cout<<num<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ttt;
	return 0;
}

