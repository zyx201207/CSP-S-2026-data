#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=-1,sum;
bool f[200010],flag=1;
void dfs(long long i,long long now){
	if(i==m+1){
		ans=max(now,ans);
		return ;
	}
	for(int j=1;j<=n;j++)
		if(!f[j]) f[j]=1,dfs(i+1,now & a[j]),f[j]=0;
}
bool check(long long x){
	while(x){
		if(x%2==1) return 0;
		x/=2;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i])) flag=0;
	}
	if(flag){
		sort(a+1,a+n+1,greater<long long>());
		cout<<a[m];
	}
	sum=a[1];
	for(int i=2;i<=n;i++)
		sum &= a[i];
	if(m==n) {cout<<sum; return 0;}
	for(int i=1;i<=n;i++)
		f[i]=1,dfs(2,a[i]),f[i]=0; 
	cout<<ans;
	return 0;
}
