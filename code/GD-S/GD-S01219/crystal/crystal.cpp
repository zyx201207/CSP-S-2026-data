#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005]; 
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1,s=0;i<=n;i++){
		s+=a[i];
		while((i-j+1)*a[i]-s>m&&j<=i){
			s-=a[j];
			j++;
		}
		if((i-j+1)*a[i]-s<=m){
			ans=max(ans,(i-j+1));
		}
	}
	cout<<ans;
	return 0;
} 
