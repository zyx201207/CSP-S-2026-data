#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int an[N];
int n,m,zd=0;
void dfs(int d,int gs,int sum){
	if(gs==m){
		zd=max(sum,zd);
		return;
	}
	if(sum<sum and an[d])dfs(d+1,gs+1,sum and an[d]);
	dfs(d+1,gs,sum);
}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>an[i];
	for(int i=1;i<=n;i++){
		dfs(i-1,0,an[i-1]);
	}
	cout<<zd;
	return 0;
} 
