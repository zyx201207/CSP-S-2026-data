#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005],ans;
bool vis[2005];
int f(int x,int y)
{
	int sum=0,k=1;
	while(x||y){
		if(x%2==y%2){
			sum=sum+k;
		}
		x>>=1;
		y>>=1;
		k*=2;
	} 
	return sum;
}
void dfs(int x){
	if(x==m+1){
		long long sum=0;
		int i=1;
		for(;i<=n;i++){
			if(vis[i]){
				sum=a[i];
				break;
			}
		}
		for(;i<=n;i++){
			if(vis[i]){
				sum=f(sum,a[i]);
			}
		}
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
