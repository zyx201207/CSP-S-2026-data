#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
long long a[N],ans;
void dfs(int step,long long res,int k){
	if(step>=m){
		ans=max(res,ans);return;
	}
	if(res<=ans)return;
	for(int i=k;i<=n;i++){
		dfs(step+1,res&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long sum=2147483647;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum&=a[i];
	}
	if(n==m){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)dfs(0,sum,i);
	cout<<ans;
	return 0;
}
