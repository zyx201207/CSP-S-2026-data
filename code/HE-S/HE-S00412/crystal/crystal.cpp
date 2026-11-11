#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,z;
int a[500005],b[500005];
int main(){
	freopen(" crysta.in","r",stdin);
	freopen(" crysta.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ma=1;
	for(int j=n;j>=1;--j){
		z=m;
		ans=1;
		for(int i=j-1;i>=1;--i){
			if(z-a[j]+a[i]>=0){
				z-=a[j]-a[i];
				ans++;
			}
		}
		ma=max(ans,ma);
	}
	cout<<ma;
	return 0;
}
