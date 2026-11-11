#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0,l=1,r=1,s=0;
	while(l<=r&&r<=n){
//		cout<<l<<' '<<r<<' '<<s<<endl;
		r++;s=(r-l+1)*a[r]-(pre[r]-pre[l-1]);
		if (s>m){
			while(l<=r&&s>m){
				l++;s=(r-l+1)*a[r]-(pre[r]-pre[l-1]);
			}
			ans=max(ans,r-l+1);
		}else ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
