#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],maxn=-1;
void dfs(long long cnt,long long sum,long long ans){
	if(ans==m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=cnt+1;i<=n;i++){
		ans++;
		dfs(i,sum&a[i],ans);
		ans--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++) maxn&=a[i];
		cout<<maxn;
	}else{
		for(int i=1;i<=n-m+1;i++) dfs(i,a[i],1);
    	cout<<maxn;
	}
	
	return 0;
}
