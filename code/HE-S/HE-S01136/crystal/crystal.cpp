#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long zu[500005];
int n;
long long m;
long long k=1;
long long ans,maxz=0;
d(long long now,long long cnt,long long sum){ //这根本就不能输入大数据 
	cnt+=zu[now]; //看看到这个数操作了几次 
	if(cnt>m){ //操作次数过多 
		cnt-=zu[now]; //结束啦  
		return sum;
	}
	sum++; //记录有几个水晶可以合并
	if(cnt==m) return sum;//如果操作数正好相等 就return可以合并的数量 
	for(long long i=now+1;i<k;i++){ //深搜往后找 
		long long tmp=d(i,cnt,sum);
		if(maxz<=tmp) maxz=tmp;//给maxz找max
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n); //从小到大排序 
	for(;k<n;k++){
		zu[k-1]=a[k]-a[k-1]; //计算从k-1到k需要多少步 
		for(int j=0;j<k-1;j++) zu[j]=zu[j]+zu[k-1]; //计算从j到k需要多少步，重复利用数组 
		ans=d(0,0,0); //这里好像只剩个调用的作用了 懒得改了 
	}
	maxz++; //把k本身那个数算上 
	cout<<maxz;
	return 0;
} 
