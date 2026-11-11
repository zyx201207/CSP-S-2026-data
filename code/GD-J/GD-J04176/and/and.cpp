#include<bits/stdc++.h>
using namespace std;
int a[200005];
int max1=0;
int n,m;
void dfs(int i,int num,int he){
	if(num==m){
		max1=max(max1,he);
		return ;
	}
	if(i==n+1) return ;
	if(num==0){
		dfs(i+1,0,0);
		dfs(i+1,1,a[i]);
	}else{
		dfs(i+1,num,he);
		dfs(i+1,num+1,he&a[i]);
	}
	return ;
} 
//5 3 31 3 1 15 7
//4 2 3 15 12 12
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}
		cout<<max1;
		return 0;
	}
	dfs(1,0,0);
	cout<<max1;
	return 0;
} 
