#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100];
long long sum[500100];
int fans;
int w[500100];//i点为到达点的最远向前延伸距离 
int pd(int d){ 
	int p;//上一个末位
	for(p=w[d-1];p<=d;p++){
		long long s=a[d]*(d-p+1);
		long long sj=sum[d]-sum[p-1];
		long long c=s-sj;
		if(c<=m)break;
	} 
	w[d]=p;
	return p;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<sum[i];
//	}

	//末位pd测试
	//... 

	//for处理n个数
	for(int i=1;i<=n;i++){
		//对于每一个数进行判断末位
		int p=pd(i);
		//将答案和fans比较
		int ans=i-p+1;
		if(ans>fans){//更新 
		 	fans=ans;
		} 
	} 
	cout<<fans;
	return 0;
}
