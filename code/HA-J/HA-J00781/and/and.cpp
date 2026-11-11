#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],f[200005],maxx=-1,mx=-1;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int sum){
	if(y==m){
		maxx=max(sum,maxx);
		return;
	}
	if(x==n+1){
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			dfs(x+1,y+1,sum&a[x]);
		}else{
			dfs(x+1,y,sum);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	f[0]=INT_MAX;
	int ans=f[0];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		ans=ans&a[i];
	}
	
	if(n<=20){
		dfs(1,0,f[0]);
		cout<<maxx;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		int sum=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i==m){
			cout<<a[i];
		}
	}
	return 0;
}
