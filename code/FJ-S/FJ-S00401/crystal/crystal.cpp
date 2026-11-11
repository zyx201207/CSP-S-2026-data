#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,a[600001] = {0},b[600001] = {0},bb[600001] = {0};
bool check(int d){
//	cout<<"ck:"<<d<<endl;
	int g = 0;
	for(int i = d;i<=n;i++){
		g-=(b[i]-b[i-d]);
		g+=a[i]*d;
//		cout<<b[i]<<" "<<b[i-d+1]<<" "<<a[i]*d<<" "<<g<<endl;
		if(g<=m)return true;
		g = 0;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		b[i] = b[i-1]+a[i];
	}
//	for(int i = 1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
//	for(int i = 1;i<=n;i++)cout<<bb[i]<<" ";
//	cout<<endl;
	int l = 1,r = n,ans = 1;
	while(l<=r){
		int mid = l+r>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid-1;
		}
	}
	cout<<ans<<endl;
//	for(int i = 1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	int g = 0;
//	for(int i = 2;i<=n;i++){
//		g+=(a[i]-a[i-1])*(i-1);
//		if(i%50==0 or i>313300)cout<<g<<" "<<i<<" "<<a[i]<<" "<<a[i-1]<<endl;
//		if(g>m){
//			cout<<i-1<<endl;
//			return 0;
//		}
//	}
//	cout<<n<<endl;
	return 0;
}
/*
7 5
1 2 4 4 4 5 6
*/
