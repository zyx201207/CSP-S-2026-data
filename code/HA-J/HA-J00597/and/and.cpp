#include<bits/stdc++.h>
using namespace std;
long long n,g,ma,a[200005];
void dfs(int x,int k,long long sum){
	if(k==g){
		ma=max(sum,ma);
		return;
	}else if(x>n) return;
	dfs(x+1,k,sum);
	if(k==0)	dfs(x+1,k+1,a[x]);	
	else	dfs(x+1,k+1,sum&a[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>g;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(g==1){
		for(int i=1;i<=n;i++)	ma=max(ma,a[i]);
	}
	else if (n==g){
		ma=a[1];
		for(int i=2;i<=n;i++)   ma=ma&a[i];
	}
	else dfs(1,0,0);
	cout<<ma;
	return 0;
}

