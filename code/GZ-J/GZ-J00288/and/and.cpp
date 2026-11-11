//GZ-J00288 ·½êÉÓî 
#include <bits/stdc++.h>
#define upp(i,a,b,c) for(int i=a;i<=b;i+=c)
#define dow(i,a,b,c) for(int i=a;i>=b;i-=c)
#define ll long long
using namespace std;
int n,m;
int a[200005];
ll dfs(ll sum,int fi,int b){
	if(fi==n+1 && b==m) return sum;
	else if(fi==n+1) return 0;
	if(b==m) return sum;
	else return (max(dfs(sum&a[fi],fi+1,b+1),dfs(sum,fi+1,b)));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		upp(i,1,n,1) cin>>a[i];
		cout<<dfs(4294967295,1,0);
	} 
	else{ 
		int minn=INT_MAX;
		upp(i,1,n,1){
			cin>>a[i];
			minn=min(minn,a[i]);
		}
		cout<<minn;
	}
	return 0;
}
