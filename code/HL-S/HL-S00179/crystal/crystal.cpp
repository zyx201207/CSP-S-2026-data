#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=(int)(5e5+5);
long long n,m,l,a[MAXN],d[MAXN],cnt[MAXN],flag1=1,flag2=1,maxn=-1;
long long pre[MAXN];//前缀和 
//long long MA=1e5;
long long baoli(int st){//用st做基准 
	int c=0,M=m;
	while(1){
		l=a[st]-a[st-c];
		if(st!=c&&M>=l) c++,M-=l;
		else break;
	}
	return c;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);//一定先排序！！！！！ 
	for(int i=1;i<=n;i++){
		//pre[i]=pre[i-1]+a[i];
		if(i>=1&&a[i]!=i) flag1=0;
		if(i>=2&&a[i]-a[i-1]!=a[2]-a[1]) flag2=0;
	}
//	for(int i=1;i<=n;i++){
//		a[i]+=MA;//处理可能出现的负数 
//		d[i]=a[i]-a[i-1];//差分 
//		cnt[a[i]]++;//找众数（不一定有用） 
//	}
		
//	if(flag1==1){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}//满足特殊性质A ai=i 
	if(flag1==1||flag2==1){//满足特殊性质B（包括特殊性质A） 等差数列 30分 
		int ans=min(m/abs(a[2]-a[1]),n);//m/公差(整除) 
		cout<<ans;
		return 0;
	}
	else if(n*n<=(long long)(1e9)/m){//O(n2*m)暴力 25分 
		for(int i=2;i<=n;i++){//枚举用每个数a[i]做基准 
			maxn=max(maxn,baoli(i));
		}cout<<maxn;
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7

4


5 5
1 2 4 8 9

3


10 39
-15 1 5 9 13 -11 -7 -3 17 21

9
*/
