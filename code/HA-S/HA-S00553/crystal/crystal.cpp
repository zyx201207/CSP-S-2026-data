#include<bits/stdc++.h>
#define in :
#define int long long
using us=unsigned;
using namespace std;
template<typename T>
void read(T& a) {
	cin>>a;
	return void();
}
template<typename T,typename... Args>
void read(T& a,Args&... args) {
	read(a);
	read(args...);
	return void();
}
template<typename T>
void print(T a) {
	cout<<a;
	return void();
}
template<typename T,typename... Args>
void print(T a,Args... args) {
	print(a);
	print(args...);
	return void();
}
const int N = 5e5;
int n,m;
int a[N+10];
int sum[N+10];
inline bool check(int number,int index) {
	if(number*a[index]-(sum[index]-sum[index-number])<=m) {
		return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n,m);
	for(us i=1;i<=n;i++) {
		read(a[i]);
	}
	sort(a+1,a+n+1);
	for(us i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(us i=1;i<=n;i++) {//a[i]是最大的
		int maxx=i;//最多连续几个
		int minn=1;
		while(minn<maxx-1) {
			const int mid = (minn+maxx)>>1;//期望有mid个
//			print(minn,' ',mid,' ',maxx,'\n');
			if(check(mid,i)) {
				minn=mid;
			} else {
				maxx=mid-1;
			}
		}
		if(check(maxx,i)) {
			ans=max(ans,maxx);
		} else {
			ans=max(ans,minn);
		}
	}
	print(ans,'\n');
	return 0;
}