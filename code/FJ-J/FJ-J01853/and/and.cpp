#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-INT_MAX;
int a[200005];
void dfs(long long i,long long sum,long long cnt){
	if(i>n){
		return ;
	}
	if(cnt==0){
		sum=a[i];
		cnt++;
	}else{
		sum=sum&a[i];
		cnt++;
	}
	if(cnt==m){
		maxn=max(maxn,sum);
		return;
	}
	for(int j=i+1;j<=n;j++){
	    dfs(j,sum,cnt);
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
		dfs(i,a[i],0);
	}
	cout<<maxn;
	return 0;
}
