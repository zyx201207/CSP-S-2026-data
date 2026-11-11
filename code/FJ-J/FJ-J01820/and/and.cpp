#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N],ans;
int cmp(int x,int y){
	return x>y;
}
int dfs(int num,int space,int step){
	if(step==m){
		int e=0;
		for(int i=space;i<=n;i++){
			e=max(num&a[i],e);
		}
		return e;
	}
	if(step>m)return 0;
	int maxn=0;
	for(int i=space+1;i<=n;i++){
		maxn=max(dfs(num&a[i],i,step+1),maxn);
	}
	return maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dfs(a[i],i,1));
	}
	cout<<maxn;
	return 0;
}
