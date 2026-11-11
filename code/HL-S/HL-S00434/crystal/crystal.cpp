#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m,ans=1;
bool cmp(int A,int B){
	return A<B;
}
int pre[N];
void solve(int k){
	int l=1;
	int r=k;
	while(l<r){
		int mid=(l+r)/2;
		int o=pre[k]-pre[mid-1];
		int len=k-mid+1;
		int p=len*a[k];
		if(p-o<=m){
			ans=max(ans,len);
			r=mid;
		}
		else l=mid+1;

	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}