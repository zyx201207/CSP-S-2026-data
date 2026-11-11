#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005],res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int id=n,cnt=0;
	for(int i=n;i>=1;i--){
		if(i<n){
			cnt-=(a[i+1]-a[i])*(i+1-id);
		}
		while(cnt+(a[i]-a[id-1])<=m&&id>1){
			id--;
			cnt+=(a[i]-a[id]);
		}
		ans[i]=i-id+1; 
	}
	for(int i=1;i<=n;i++){
		res=max(res,ans[i]);
	}
	cout<<res;
	return 0;
}
/*3 99
2 2 88*/
