#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn=INT_MIN;
long long arr[200010];
int w[40];
void dfs(long long num,long long ai,long long ans){
	
	if(ans>m){
		maxn=max(maxn,num);
		num=0;
		return;
	}
	if(ai>n) return;
	dfs(num&arr[ai++],ai+1,ans+1);
	cout<<num<<endl;
	dfs(num,ai+1,ans);
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		dfs(arr[i],i,1);
	}
	
	cout<<maxn;
	return 0;
}
