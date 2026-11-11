#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=1,sum,a[N],b[N],c[N];
bool cmp(int x,int y){
 	if((x-y)>(y-x)) return false;
 	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	int i=2; 
	while(sum<=m&&i<=n){
		sum+=b[i]*(i-1);
		ans++;i++;
	}
	if(sum>m) ans--;
	cout<<ans<<endl;
	return 0;
} 
