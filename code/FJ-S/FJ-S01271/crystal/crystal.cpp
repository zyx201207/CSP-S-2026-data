#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],minn=(1e13),maxx=-(1e13),l,r,mid,ans,f=1;//1e18之力 
bool check(int num){
	int lf=1,ansf=0;
	while(a[lf]<num){
		ansf=ansf+(num-a[lf]);
//		cout<<num<<" "<<a[lf]<<endl;
		lf++; 
	}
	
	if(ansf>m) return false;
	else return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
//		cin>>a[i];
		scanf("%lld",&a[i]);
		minn=min(minn,a[i]);//找最大最小 
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1); 
//	cout<<minn<<endl<<maxx;
	l=minn;
	r=maxx;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)==true){//符合条件 
			l=mid;
//			cout<<1;
		}else{
			r=mid-1;
//			cout<<0;
		}
//		cout<<l<<" "<<mid<<" "<<r<<endl;
	}
//	cout<<l;
	while(a[f]<=l){
		ans++;
		f++;
	}
//	cout<<ans;
	printf("%lld",ans);
}
//abcdefghijklmnopqrstuvwxyz
/*
这无疑是神圣的
先排序
水晶范围是2*10^12，log2*10^12=40.863137138648348174443833153873,常数小
可以从最小的水晶开始，把所有a_i<k(k为整数)的水晶能量值补到k，所需m次
那我们就从min a_i(-10^12)~max a_i(10^12)之间二分k，判断m是否满足条件,找右端点 
每次判断扫一遍n(5*10^5)
ohhhhhhhhhhhhhhh 亿铂昏！
想多了 nooooooooooooooo！ 
构造数据
6 10
1 1 98 100 99 101
二分结果是6，将两个1补到6，结果为2 
但答案是4，将右侧的四个数据补到101 
那就从平均值开始？ 
构造数据
9 215
1 1 1 1 1 98 100 99 101
平均值44.7，记为44 
二分结果是44，将5个1补到44，结果为5 
但答案是6，将右侧的四个数据和两个1补到101
算了,有多少是多少吧 
大样例证明有时是对的 
问题：如果数据可被分为几块，每一块内数据差距不大，但块与块之间相差极大，那么会错
*/
