#include<bits/stdc++.h>
using namespace std;
long long n,m,a[201000],v[201000],f,ans;
void dfs(long long k,long long sum){
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			k+=1;
			dfs(k,sum&a[i]);
			k-=1;
			v[i]=0;
		}
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	f=pow(2,31);
	f=f-1;
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(1,a[i]);
		v[i]=0;
	}
	cout<<ans;
	return 0;
} 



