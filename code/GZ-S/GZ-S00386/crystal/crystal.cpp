//GZ-S00386 吴显鑫 
#include<bits/stdc++.h>
/*
先排序 
我们可以用一个差分来看到底要加多少才能保持一样 
1.暴力枚举当i为水晶时，用一个数组来表示这些数-i的差值，并依次取值 o（n^2）
2.先根据最大的数找出每个数与其的差值， 向前枚举再通过二分找到如果这些数字都与i相同时所能得的最大值 每一次的这n数的和等于上一次的和减去n*（i+1-i） 
3. 如果max大于i就不用枚举了 
*/
using namespace std;
int n;
long long m;
long long a[1000010]; //llabs
long long c[1000010];
long long q[1000010];
long long ma;
bool check(int todayy,int noww) { //today表这次循环的右端点，now表这次循环的左端点 
	int num=(q[todayy]-q[noww-1])-(todayy-noww+1)*(a[n]-a[todayy]);//目前的前缀和- 
	if(num>m) return true;
	else return false;
}
long long f(int p) {  
	//最后一个小于等于的，也就是第一个大于的 
	int l=1,r=p;
	long long ans=0;
	while(l<=r) {
		long long mid=(l+r)/2;
		if(check(p,mid)) {
			l=mid+1;
			//cout<<"A"<<r;
		} else {
			ans=mid;
			r=mid-1;
			//cout<<"B"<<l;
		}
		//cout<<l<<" "<<r<<" "<<mid<<" "<<check(p,mid)<<" "<<ans<<endl;
		//cout<<ans;
	}
	return ans;
}
int main() {
	freopen("crystal.in","r",stdin);//注意等一下修改 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		c[i]=a[n]-a[i];
	} 
	for(int i=1;i<=n;i++) {
		q[i]=q[i-1]+c[i];
	} 
	for(int i=n;i>=2;i--) {
		//cout<<i<<endl;
		long long manow=f(i);
		//cout<<manow<<endl<<endl;
		if(manow!=-1) ma=max(ma,i-manow+1);
		//if(ma>i) break;
		
	}
	cout<<max(ma,(1LL)*1);
	return 0;	
}
