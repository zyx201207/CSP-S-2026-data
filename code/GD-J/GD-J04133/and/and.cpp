#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N];
long long ans=0;
void dfs(int q,long long sum,int b){
	if(q==m+1){
		ans=max(ans,sum);
		return;
	}
	for(int y=b;y<=n;y++){
		dfs(q+1,sum&a[y],y+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	if(m==1){
		ans=0;
		for(int x=1;x<=n;x++){
			ans=max(ans,a[x]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int x=2;x<=n;x++){
			ans=ans&a[x];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ans=0;
		for(int x=1;x<n;x++){
			for(int y=x+1;y<=n;y++){
				ans=max(a[x]&a[y],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int x=1;x<=n;x++){
		dfs(2,a[x],x+1);
	}
	cout<<ans;
	return 0;
}
