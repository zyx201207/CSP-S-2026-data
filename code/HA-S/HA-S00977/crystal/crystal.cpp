#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],s[10000000],ss[10000000],minn;
bool check(long long x){
	long long sum=1e18;
	for(int i=0;i+x<n;i++){
		int l1=i+1,r1=i+x;
		sum=min(sum,a[r1]*(x-1)-ss[r1-1]+ss[l1-1]);
	}
	return sum<=m;
}//距离or数轴的思想建立前缀和 跑二分答案 考点：数学+二分 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]<0){
		int k=a[1];
		for(int i=1;i<=n;i++){
			a[i]-=k;
		}
	}
	for(int i=1;i<=n;i++){
		ss[i]=a[i]+ss[i-1];
	}
	long long l=1,mid,r=n;
	while(l<r){
		mid=(1+l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
