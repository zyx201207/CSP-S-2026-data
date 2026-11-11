#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],ans=1;
int check(int x){
	int c=1;
	for(int j=x-1;j>=1;j--){
		if((x-j+1)*a[x]-(s[x]-s[j-1])<=m){
			c=x-j+1;
		}else break;
	}return c;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,check(i));
	}cout<<ans;
	return 0;
}
