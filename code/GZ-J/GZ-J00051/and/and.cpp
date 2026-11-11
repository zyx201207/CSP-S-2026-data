//Ìï•×¶÷GZ-J00051
#include<bits/stdc++.h>
using namespace std;
long long max_sum,sum;
int n,m,maxx=-1e8,a[2005];
void dfs(int u,long long cur,int last){
	if(n-last<m-u){
		return;
	}
	if(u==m){
		max_sum=max(max_sum,cur);
		return;
	}
	for(int i=last+1;i<=n;i++){
		dfs(u+1,cur&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sum=a[1];
	for(int i=2;i<=n;i++){
		sum&=a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		cout<<sum;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(1,a[i],i);
		}
	}
	cout<<max_sum;
	return 0;
} 
