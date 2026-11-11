#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005][10005];
int ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[1][i];
	if(m==1){
		for(int i=1;i<=n;i++)	ans=max(ans,a[1][i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1][1];
		for(int i=2;i<=n;i++)	ans=ans&a[1][i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int g=1000000000;
		for(int i=1;i<=n;i++)	g=min(g,a[1][i]);
		ans=a[1][1];
		for(int i=2;i<=n;i++)	if(a[1][i]!=g)	ans&=a[1][i];
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n-1;j++){
		int g=-1;
		for(int k=j+1;k<n;k++){
				g=max(g,a[1][j]&a[1][k]);
		}
		a[2][j]=g;
	}
	for(int i=1;i<=n-1;i++){
		ans=max(ans,a[2][i]);
	}
	cout<<ans;
	return 0;
}
