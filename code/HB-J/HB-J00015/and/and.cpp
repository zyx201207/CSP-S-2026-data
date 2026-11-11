#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200001],book[21],aa=0;
void dfs(int x){
	if(x>m){
		int ans=-1;
		for(int i=1;i<=n;i++) if(book[i]==1) if(ans==0)ans=a[i]; else ans=ans&a[i];
		aa=max(aa,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==1) continue;
		book[i]=1;
		dfs(x+1);
		book[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans; 
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<aa;
		return 0;
	}
	cout<<2;
	return 0;
}
