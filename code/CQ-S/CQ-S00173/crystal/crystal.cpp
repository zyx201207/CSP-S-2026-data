#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500001],k[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) k[i]=k[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int u=1;u<=i-ans;u++){
			for(int j=i;j>=u;j--){
				if(j<=ans) break;
				if(m<a[i]*j-k[j]) continue;
				ans=max(ans,j);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
