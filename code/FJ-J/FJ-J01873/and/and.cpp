#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
inline void dfs(long long sum,long long la,long long num){
	if(num==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=la+1;i<=n;i++){
		if(n-i+2+num<=m)break;
		dfs(sum&a[i],i,num+1);
	}
}
inline int pd(long long x){
	while(x>1){
		if(x%2==1)return 1;
		x/=2;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int f1=1,f2=1;
	long long s=(1<<40)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];s&=a[i];
		if(pd(a[i]+1)==0)f1=0;
		if(a[i]!=i-1)f2==0;
	}
	sort(a+1,a+n+1);
	if(f1){
		cout<<a[n-m];
		return 0;
	}
	if(n==m){
		cout<<s;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(f2){
		cout<<n-m;
		return 0;
	}
	dfs((1<<40)-1,0,0);
	cout<<ans;
	return 0;
}
