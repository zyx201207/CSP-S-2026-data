#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005]; 
long long maxx;
void dfs(int x,int s,long long t){
	if(s==m){
		maxx=max(maxx,t);
		return ;
	}
	if(x>n||n-x<m-s){
		return ;
	}
	if(s==0){
		dfs(x+1,s+1,a[x]);
	}else{
		dfs(x+1,s+1,a[x]&t);
	}
	dfs(x+1,s,t);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum=1,summ,k=0;
	bool f=0,flag=1;
	while(sum<n){
		if(sum*2>=m&&!f){
			summ=sum*2-1;
			f=1;
		}
		sum*=2;
		k++;
	}
	
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)flag=0;
	}
	if(sum==n&&flag){
		cout<<n-1-summ;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxx;
	return 0;
}
