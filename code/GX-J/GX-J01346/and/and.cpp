#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200010];
int n,m,ans;
void dfs(int start,int depth,int num){
	if(depth==m){
		if(num>ans) ans=num;
		return;
	}
	if(start+m==n) return;
	for(int i=start;i<n;i++){
		if(depth==0) dfs(i+1,depth+1,a[i]);
		else dfs(i+1,depth+1,num&a[i]);
	}
}
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	dfs(0,0,a[0]);
	cout<<ans;
	return 0;
}
