#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005];
bool check(int x){
	int k=0,la=0;
	for(int i=x;i>=1;i--){
		k+=a[x]-a[i];
		if(k<=m) la++;
		else break;
	}
	return la>=ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

