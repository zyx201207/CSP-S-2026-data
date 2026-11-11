#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N];
int calc(long long x,int R){
	int l=1,r=R;
	while(l<r){
		int mid=l+r>>1;
		if((R-mid+1)*x<=m+a[R]-a[mid-1])r=mid;
		else l=mid+1;
	}
	return R-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=max(ans,calc(a[i],i-1)+1);
		a[i]+=a[i-1];
	}
	cout<<ans;
	return 0;
}

