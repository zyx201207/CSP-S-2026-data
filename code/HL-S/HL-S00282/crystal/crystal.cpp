#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,a[N],m,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//	cout<<n<<" "<<m<<endl;
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;r++){
		if(r>1) sum+=(r-l)*(a[r]-a[r-1]);
//		cout<<l<<" "<<r<<" "<<sum<<endl;
		while(sum>m) sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<" "<<sum<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
zhui yi,sheng xuan lian kao 2025
wo chang chang zhui yi guo qu.
sheng ming shun jian ding ge zai nao hai,wo jiang bei hou de shi jian cai jian,quan qu,rou nie cheng tian shang duo duo bai yun.
yun duo zhi jian yi you fen bie,ji yun hou zhong,er juan yun piao miao.
zhong jian wang le.
wo gai zai na li ting liu,wo wen wo zi ji.
*/
