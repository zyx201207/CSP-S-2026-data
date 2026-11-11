//GZ-J00508 敖翔 兴义市弘毅中学  
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n,greater<long long>());
	ans=a[0];
	for(long long i=1;i<m;i++) ans=ans&a[i];
	cout<<ans<<'\n';
	return 0;
} 
