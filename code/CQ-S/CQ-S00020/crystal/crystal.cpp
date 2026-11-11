#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans,s[N];
#undef int 
int main(){
#define int long long 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int an=1;
		for(int j=20;j>=0;j--){
			int mid=an+(1<<j);if(mid>i)continue;
			if(mid*a[i]-s[i]+s[i-mid]<=m)
				an=mid;
		}
		ans=max(ans,an);
		// if(an==4236){
		// 	cerr<<i<<" "<<an<<endl;
		// 	cerr<<an*a[i]-s[i]<<" "<<m<<endl;
		// 	int sum=0;
		// 	for(int j=1;j<=i;j++){
		// 		sum+=a[j];
		// 		if(sum!=s[j]){
		// 			cerr<<"!  "<<j<<" "<<sum<<" "<<s[j]<<endl;
		// 		}
		// 	}
		// 	cerr<<sum<<" "<<s[i]<<endl;
		// 	exit(0);
		// }
	}
	printf("%lld\n",ans);
	return 0;
}