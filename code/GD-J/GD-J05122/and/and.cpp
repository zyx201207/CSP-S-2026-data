#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx;
void dfs(long long i,long long k,long long num){
	if(k==m){
		maxx=max(maxx,num);
		return;
	}
	for(i=i+1;i<n;i++){
		dfs(i,k+1,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,1,a[i]);
	}
	cout<<maxx;
	return 0;
} 
