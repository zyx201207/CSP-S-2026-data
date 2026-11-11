#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;//10^18必须开long long 
long long a[500010],qzh[500010];//10^12,10^17必须开long long; 
bool solve(int x){
	for(int i=x;i<=n;i++){//访问每个长度为x的连续区间 
	    long long p=x*a[i]-qzh[i]+qzh[i-x];//该区间所有元素加到同一值操作数
		if(p<=m){//若小于m,符合 
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	qzh[0]=0;//初始化第零项为零 
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];//求求前缀和,使区间查询为o(1) 
	}
	int l=1,r=n;//二分答案，求最大长度
	while(l<=r){
		int mid=(l+r)>>1;
		if(solve(mid)){//该答案可行，增大
		    ans=mid;//记录答案 
			l=mid+1; 
		}else{//不可行减小 
			r=mid-1;
		}
	} 
	printf("%d",ans);
	return 0;
}

