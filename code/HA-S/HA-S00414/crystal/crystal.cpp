#include<bits/stdc++.h>
using namespace std;
int n,m,ma;long long a[500005];
void dfs(int x,int sum,int k,long long y){
	if(x>n && k!=0){
		if((sum+m)%k==0 && (sum+m)/k==y) ma=max(ma,k);
		return;
	}
	else if(k==0 && x>n) return;
	dfs(x+1,sum,k,y);
	dfs(x+1,sum+=a[x],k+1,max(y,a[x]));
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1,0,0,0);
	cout<<ma;
	return 0;
}

