/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],z;
bool f[200010];
void dfs(long long c,long long d){
	if(c>m){
		z=max(z,d);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			if(d==0){
				dfs(c+1,a[i]);
			}else{
				dfs(c+1,(d&a[i]));
			}
			f[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<z;
	return 0;
}
