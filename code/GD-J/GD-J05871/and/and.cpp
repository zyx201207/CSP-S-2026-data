#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ma;
int b[200005];

void dfs(int x,int q){
	if(x>m){
		int sum;
		sum=b[1];
		for(int i=2;i<=m;i++){
			sum&=b[i];
		}
		ma=max(ma,sum);
		return;
	}
	for(int i=q;i<=n;i++){
		b[x]=a[i];
		dfs(x+1,i+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
