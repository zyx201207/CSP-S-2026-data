//GZ-J00473 遵义市第四初级中学 陈昊然
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long mx=-2e9;
void d(long long cnt,long long ans) {
	if(cnt==0) {
		mx=max(mx,ans);
		return;
	}
	for(int i=0; i<=n-1; i++) {
		long long sum=0;
		if(cnt==m) {
			ans=a[i];
			sum=ans;	
		}else{
			sum=ans & a[i];
		}
		d(cnt--,sum);
		return;
	}
}
int main() {
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<=n-1; i++) {
		cin>>a[i];
	}
	d(m,0);
	cout<<mx;
	return 0;
}

