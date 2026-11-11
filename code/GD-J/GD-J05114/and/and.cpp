//and
//前缀和

#define LL long long
#include <bits/stdc++.h>
using namespace std;

//似乎位与不能用前缀和
LL m,n;
LL num[200010];
LL ans=-1LL;
//全部都是2^k-1 
bool check(LL num[200010]) {
	for(int i=0;i<n;i++) {
		if(((num[i]+1)&num[i])!=0) return false;
	}
	return true;
}
//n=2^k,a[i]=i-1
bool check2(LL num[200010]) {
	if(n&n-1!=0) return false;
	if(num[0]!=0) return false;
	for(int i=1;i<n;i++) {
		if(num[i]-num[i-1]!=1) return false;
	}
	return true;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(LL i=0;i<n;i++) {
		cin>>num[i];
	}
	//全部都是2^k-1
	if(check(num)) {
		sort(num,num+n,greater<LL>());
		cout<<num[m-1]<<endl; 
		return 0;
	}
	//n=2^k,a[i]=i-1
	if(check2(num)) {
		cout<<num[n-m+1]<<endl;
		return 0;
	}
	
} 
/*LL m,n;
LL num[200010];
LL sum[200010];
LL ans=-2147483648LL;

int main() {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	//数据似乎有点大，加个速 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	cin>>num[1];
	sum[1]=num[1];
	for(LL i=2;i<=n;i++) {
		cin>>num[i];
		sum[i]&=sum[i-1]&num[i];  //前缀和变式 
	}
	//num[l]&num[l+1]&num[l+2]&...&num[r-1]&num[r]=sum[r]&sum[l-1];
	for(LL l=1;l<=n-m+1;l++) {   //选开头
		LL r=l+m-1;
		LL val=sum[r]&sum[l-1];  //位与和 
		ans=max(ans,val);        //打擂台 
	} 
	
	cout<<ans<<endl;
	return 0;
} */
