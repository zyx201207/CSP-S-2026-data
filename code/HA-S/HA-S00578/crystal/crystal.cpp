#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool check(int mid){
	int res=0;
	for(int i=1;i<mid;i++){
		res+=a[mid]-a[i];
	}
	if(res<=m)ans=max(ans,mid);
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}

