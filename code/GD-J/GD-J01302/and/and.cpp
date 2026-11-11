#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,ma,a[200005],b[200005],mi,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=min(int(pow(10,7))/n,n-m);i++){
		ans=a[i];
		for(int j=1;j<m;j++){
			ans=ans&a[i+j];
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
