#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
long long a[500010];
void dfs(int x){
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j]==a[i]) sum++;
		}
		maxn=max(sum,maxn);
	}
	if(x==m+1) return;
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(x+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int A=1,B=1,num;
	if(n<2){
		cout<<1;
		return 0;
	}
	cin>>a[1]>>a[2];
	num=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) A=0;
		if(a[i]-a[i-1]!=num) B=0; 
	}
	if(A==1){
		int i=1;
		for(i=1;i*(i+1)/2<=m;i++);
		i--;
		cout<<min(n,i);
		return 0;
	}
	if(B==1){
		int i;
		for(i=1;(num+i*num)*i/2<=m;i++);
		cout<<min(i,n);
		return 0;
	}
	dfs(1);
	cout<<maxn;
	return 0;
} 
