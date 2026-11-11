#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x[200005],ans,t;
bool f=true;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long step){
	if(step>m){
		long long s=a[x[1]];
		for(int i=2;i<=m;i++){
			s=s&a[x[i]];
		}
		ans=max(ans,s);
		return;
	}
	for(int i=x[step-1]+1;i<=n;i++){
		x[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		t=a[i];
		while(t>0){
			if(t%2==0) f=false;
			t/=10;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(f==true){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
