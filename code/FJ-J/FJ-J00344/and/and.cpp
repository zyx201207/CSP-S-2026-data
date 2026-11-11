#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200004];
int ans=-1;
bool p[200004];
int check(int ed){
	int sum=-1;
	for(int i=1;i<=ed;i++){
		if(!p[i]) continue;
		if(sum==-1) sum=a[i];
		else sum=(sum&a[i]); 
	}
	return sum;
}
void dfs(int i,bool num,int mn,int cho){
	p[i]=num;
	if(mn==-1&&num) mn=a[i];
	if(num) mn=min(mn,a[i]);
	if(mn<ans) return ;
	if(cho+(n-i)<m) return ;
	if(cho>m) return ;
	if(i==n||cho==m){
		if(i==n&&cho!=m) return ;
		ans=max(ans,check(i));//就查到i 
		return ;
	}
	dfs(i+1,0,mn,cho);
	if(a[i+1]>=ans) dfs(i+1,1,mn,cho+1);
}
int main() {//与的结果最大为选的数中的最小值 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int al=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(al==-1) al=a[i];
		else al=(al&a[i]);
	}
	if(n==m){
		cout<<al;
		return 0;
	}
	if(n<=2000||(log2(m)==ceil(log2(m)))){
		dfs(0,0,-1,0);
		cout<<ans;
		return 0;
	}
	return 0;
}/*
5 3
31 3 1 15 7

*/
