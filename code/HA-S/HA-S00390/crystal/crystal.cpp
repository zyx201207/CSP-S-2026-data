#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=500005;
const int MX=1e18;
int n,m,anss=1;
int a[M],c[M],ans[M];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		ans[i]=c[i]*(i-1);
		ans[i]+=ans[i-1];
//		cout<<ans[i]<<" ";
	}
//	cout<<"\n";
	anss=upper_bound(ans+1,ans+n+1,m)-ans;
//	int l=0,r=n,mid=0;
//	while(l<=r){
//		int mid=(l+r)/2;
////		cout<<l<<" "<<r<<" "<<mid<<"\n";
//		if(ans[mid]>m){
//			anss=mid;
////			cout<<mid<<"\n";
//			r=mid-1;
//		}else{
//			l=mid+1;
//		}
//	}
	anss--;
//	int antr=(m-ans[anss]);
//	antr/=(c[anss+1]);
//	antr++;
//	cout<<max(antr,anss);
	cout<<anss<<"\n";
	return 0;
}
/*


5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4


5 11
2 4 6 8 10

*/




