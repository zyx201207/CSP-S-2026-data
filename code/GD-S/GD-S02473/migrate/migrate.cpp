#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,a[2000020],m,ans,sum,T;
int solve(int l,int r,int u){
	if(l==r){
		if(u==2)
		sum++;
	}for(int i=1;i<=m;i++){
		if(l+i<=r)
		solve(l+i,r,u+1);
	}return -1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+1+n);
	for(int i=1;i<=n-m-1;i++){
		for(int j=i+m+1;j<=n;j++){
			sum=0;
		solve(a[i],a[j],0);
		if(sum==2){
		ans++;
	}
		}
	}cout<<ans<<endl;
}
	return 0;
}
