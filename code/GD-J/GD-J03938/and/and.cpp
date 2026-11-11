#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m,s,d,f[200010],g,h,l;
void dfs(long long q){
    if(q>m){
    	long long w=f[1],e=1;
    	for(int i=2;i<q;i++){
    		if(f[i]!=0)w=w&(f[i]),e++;
		}
		if(e>=m)g=max(g,w);
		if(q>n)return ;
	}
	f[q]=a[q];
	dfs(q+1);
	f[q]=0;
	dfs(q+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1);
	cout<<g;
	return 0;
}
