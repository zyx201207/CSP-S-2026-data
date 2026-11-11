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
9:47 这个and和去年的xor是孪生兄弟吧
9:52 好像要排序？再从高到低统计一下每位1出现的次数是否大于m，最后再算回十进制 
	 这是个log，所以时间不会超 
9:55 算一下时间复杂度吧 O(n*30+30),那就是O(n),完美 
10:00 哦不对。。我不能确保哪个数字贡献了这个1
10:03 ？！二维数组？！
10:27 5 3
	  31 3 1 15 7
10:42 时间复杂度O(60*n+m),也就是1.2e7左右，不会超，写完and了okk 
*/
long long a[200010]; 
int bin[200010][40];
int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++){
		int cnt=1;
		long long cur=a[i];
		while(cur>0){
			if(cur%2!=0) bin[i][cnt]++;
			cur=cur>>1;
			cnt++;
		}
	}
	int mark;
	for(int j=31; j>=1; j--){
		int cnt=0,cur=0;
		for(int i=n; i>=1; i--){
			if(bin[i][j]==1){
				cnt++;
				cur=i;
			}
		}
		if(cnt>=m){
			mark=cur;
			break;
		}
	}
	long long ans=a[mark];
	for(int i=1; i<=m; i++){
		 ans&=a[mark];
		 mark++;
	}
	cout<<ans;
	return 0;
}
