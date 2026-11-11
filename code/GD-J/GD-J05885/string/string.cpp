#include<bits/stdc++.h>
using namespace std;
/*Trick||Treat!
8:33 CCF原来你知道今天是万圣节，好幽默的解压密码hhh
8:36 这第一题有点过分简单了哈哈，最难的部分是取一个漂亮的变量名
8:37 既然是小R和小X，那就叫cr和cx吧嗯嗯 
8:39 哇，这个数据好小 
8:44 看我三目运算符 
8:47 写一个大if更好 
8:53 ok写完了第一题,会不会有点慢了aaa 
9:05 ok填了一些东西，继续回来写游记（这应该可以吧？
9:06 还好这个数据不算大，直接枚举应该没问题？？ 
9:07 噢不对。。这肯定超了，要写优化；
9:10 是不是有数学方法？我看是
9:12 longlong是存的下L的
9:14 贪心地改应该是可以的吧？也不行，如果后面比前面长的话； 
9:23 辗转相减？ 这样的话初始化比较麻烦 
9:44 实在不会了，先写and（今年的第二题这么难吗sos？ 
11:12 回来写string 
11:22 暴力可以拿70分 
那我不如2，4两道题都写暴力 
*/
int a[200010];
long long sum[200010];
char c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long len=0;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i]; 
		len+=a[i];
	}
	long long l=1,r=len,ans=0;
	int nl=1,nr=n;
	while(l<r){
		int cnt=min(a[nl],a[nr]);
		if(l>sum[nl]) nl++;
		if(r<sum[nr]) nr--;
		if(c[nl]!=c[nr]) ans+=cnt;
		l+=cnt,r-=cnt;
	}
	cout<<ans;
	return 0;
} 
