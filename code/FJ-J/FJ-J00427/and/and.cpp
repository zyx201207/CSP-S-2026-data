/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/
//100+100+55+48=303pts
//55pts A(n,m)
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],maxn,ans;
int d[200005];
void dfs(int sumn,int summ){
	if(sumn>n&&summ<=m){
		return;
	}
	if(summ>m){
		int cnt=d[1];
		for(int i=2;i<=m;i++){
			cnt=cnt&d[i];
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			d[summ]=a[sumn];
			dfs(sumn+1,summ+1);
		}else{
			dfs(sumn+1,summ);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n>2000||m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
