#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[500005];
int k[500005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n+1;i>=2;i--){
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		k[i]=k[i-1]+c[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(k[j]-k[i]<=m){
				ans=max(ans,j-i+1);
			}	
		}
	}
	cout<<ans;
	return 0;
}
