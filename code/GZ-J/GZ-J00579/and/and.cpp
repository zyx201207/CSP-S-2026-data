//GZ-J00579 遵义市新浦新区滨湖中学  安李晨 
#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=INT_MIN,man=INT_MIN,ansx;
int a[200010];
int ans[200010];
void dfs(int t,int d,int ansi){
	if(d>m){
		return ;
	}
	for(int i=t;i<=n;i++){
		int ansii=ansi;
		ansi&=a[i];
		if(d==m) maxn=max(maxn,ansi);
		dfs(++i,++d,ansi);
		ansi=ansii;
		d--;
		i--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) ansx=a[i];
		else ansx&=a[i];
		man=max(man,a[i]);
	}
	
	if(m==1){
		cout<<man;
		return 0;
	}
	
	if(m==n){
		cout<<ansx;
		return 0;
	}
	
	if(n>2000){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<maxn;
	return 0;
}
