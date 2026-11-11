#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],mx,f;
void dfs(int cnt,int l,int u){
	if(f==5)return ;
	if(u<=0)return ;
	if(u<n-m*10)return ;
	if(u<m-l)return ;
	if(mx!=0&&mx>=cnt&&l){
		f++;
		return ;
	}else f=0;
//	cout<<a[u]<<" cnt:"<<cnt<<" u:"<<u<<" L:"<<l<<"\n";
	if(l==m){
		mx=max(cnt,mx);
		return ;
	}
	if(!l)dfs(a[u],l+1,u-1);
	else dfs((cnt&a[u]),l+1,u-1);
	dfs(cnt,l,u-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(m==n-1){
		mx=max(a[n]&a[2],max(a[n]&a[1],a[n-1]&a[1]));
	}
//	else if((long long)m*n>7e6){
//		for(int i=n-m;i<=n;i++){
//			for(int j=max(0,i-2*m);j<=max(i-m,0);j++){
//				mx=max(a[i]&a[j],mx);
//			}
//		}
//	}
	else dfs(0,0,n);
	cout<<mx;
	return 0;
}
