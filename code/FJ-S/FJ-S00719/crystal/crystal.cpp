#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			b[i]=a[i]-a[i-1];
		}
		else{
			b[i]=a[i-1]-a[i];	
		}
		c[i]=c[i-1]+b[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[j]-c[i-1]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
