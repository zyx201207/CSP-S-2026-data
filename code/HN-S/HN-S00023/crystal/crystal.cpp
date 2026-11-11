#include <bits/stdc++.h>
using namespace std;
int a[11451419],n,m,ans,minn=0x3f3f,idk;
bool idontknow(int x){
	int b=0;
	for(int i=x;i>=1;i--){
		b+=(a[x]-a[i]);
	}
	if(minn>=b){
		minn=min(minn,b);
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		//cout<<idontknow(mid)<<" ";
		if(idontknow(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
		//cout<<l<<" "<<r<<endl;
	}
	cout<<ans;
	return 0;
}
