#include <bits/stdc++.h>
using namespace std;
long long n,m,x[100005],a[100005],maxn=-1;
void dfs(int now,int my,int s){
//	cout<<s<<endl;
	if(my==0){
		if(s>maxn)maxn=s;
		return;
	}
	if(now>n)return;
	dfs(now+1,my,s);
	if(my==m){
		dfs(now+1,my-1,a[now]); 
	}
	else{
		dfs(now+1,my-1,s&a[now]); 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m,1);
	cout<<maxn;
	return 0;
}

