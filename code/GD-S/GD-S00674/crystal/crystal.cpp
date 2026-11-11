//GD-J00280 
//OK
#include<bits/stdc++.h>
#define MAXN 500100
using namespace std;
long long n,a[MAXN],m,ans,sum[MAXN];
bool check(int l,int x){
	long long s=sum[x]-sum[l-1];
	return a[x]*(x-l+1)<=s+m;
}
long long find(int x){
	int l=1,r=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,x))r=mid-1;
		else l=mid+1;
	}
	return x-l+1;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)ans=max(ans,find(i));
	cout<<ans;
	return 0;
}
/*
这题可做？
排序后做前缀和
找最小的k使得增加量不大于m
二分 



17:44
三个题都看不懂
特殊性质也不会写
100+0+0+0
rp都用到早上了
反正j1也不是不行:) 
*/
