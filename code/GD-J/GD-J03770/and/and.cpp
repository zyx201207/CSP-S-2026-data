#include<bits/stdc++.h>
using namespace std;
long long a[200005],vis[200005];
long long maxn=0;
int n,m;
bool flag=true;
void dfs(int step,long long sum){
	if(step>m){
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(flag){
				sum=a[i];
				flag=false;
			} 
			vis[i]=1;
			dfs(step+1,sum&a[i]);
			vis[i]=0;
			flag=true;
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
	dfs(1,0);
	cout<<maxn;
	return 0;
} 
