#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		long long l=0,r=i;
		while(l+1!=r){
			long long mid=(l+r)>>1;
			long long x=(i-mid)*a[i]-pre[i-1]+pre[mid-1];
			if(x<=m) r=mid;
			else l=mid;
		}
//		cout<<r<<" ";
		ans=max(ans,i-r+1);
	}
	cout<<ans;
}