#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int b[200001];
long long sum=0;
void dfs(int x,int k,long long ans){
	if(k==m){
		sum=max(sum,ans);
		return;
	}
	if(x>n) return;	
	for(int i=x;i<=n;i++){
		b[k]=i;
		dfs(i+1,k+1,ans&a[i]);b[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,LLONG_MAX);
	cout<<sum;
	return 0;
}
