#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],mx=-1;
int v[N];
void dfs(int step,long long x){
	if(step==m){
		mx=max(mx,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		long long j=x&a[i];
		dfs(step+1,j);
		v[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(1,a[i]);
		v[i]=0;
	}
	cout<<mx;
	return 0;
}
