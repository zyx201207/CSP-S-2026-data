#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long x,y,n,m,c,s,a[N],b[N],ma=-1;
void dfs(long long i,long long t,long long s){
	if(i==m){
		if(s>ma)ma=s;
		return;
	}
	for(int j=t;j<=n;j++){
		if(i==0){
			dfs(i+1,j+1,a[j]);
		}else dfs(i+1,j+1,s&a[j]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<ma;
	return 0;
}
