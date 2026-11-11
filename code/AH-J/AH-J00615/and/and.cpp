#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,a[N],m;long long sum=0;
void dfs(int j,int s,long long g){
	if(s>m){sum=max(sum,g);return;}
	if(j>n) return;
	dfs(j+1,s+1,g&a[j]);
	dfs(j+1,s,g);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,1ll*a[i]);
	}cout<<sum;return 0;}
	if(m==n){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=sum&(1ll*a[i]);
	}cout<<sum;return 0;}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<sum;
	return 0;}
