#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n,m,a[N],res,maxn;

void dfs(int idx,int sum,int cnt){//下标 按位与的和 已选的个数 
	if(cnt==m){
		res = max(res,sum);
		return;
	}
	if(idx>n){
		return;
	}
	dfs(idx+1,sum,cnt);
	if(cnt==0) dfs(idx+1,a[idx+1],cnt+1);
	else dfs(idx+1,sum&a[idx+1],cnt+1);
}

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				res = max(res,a[i]&a[j]);
			}
		}
		cout<<res;
		return 0;
	}
 	if(m==n){
		int sum = a[1];
		for(int i=2;i<=n;i++){
			sum &= a[i];
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){ 
		dfs(0,0,0);
		cout<<res;
		return 0;
	}
	sort(a+1,a+n+1);
	res = a[1];
	for(int i=2;i<=m;i++){
		res &= a[i];
	}
	cout<<res;
	return 0;
}
