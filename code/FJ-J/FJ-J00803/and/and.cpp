#include<bits/stdc++.h>
using namespace std;
long long n,m,o=0;
long long x[200005];
bool c[200005];
void dfs(long long k,long long z){
	if(k>n){
		o=max(o,z);
		return;
	}
	for(int i=1;i<=m;i++){
		if(c[i]) continue;
		c[i]=1;
		dfs(k+1,z&x[i]);
		c[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>x[i];
	}
	if(n==1){
		for(int i=1;i<=m;i++){
	    	o=max(o,x[i]);
		}
	}
	for(int i=1;i<=m;i++){
	    c[i]=1;
		dfs(2,x[i]);
	} 
	cout<<o;
	return 0;
}
