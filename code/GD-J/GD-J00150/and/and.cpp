#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct sum{
	int a;
	bool num[35];
	bool operator < (const sum other)const{ return a>other.a; }
}A[N];
int powe(int base,int k){
	int res=1;
	for(int i=1;i<=k;i++) res*=base;
	return res;
}
int n,m,cnt[35],ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i].a);
		int temp=A[i].a,cur=0;
		while(temp){
			A[i].num[cur]=(temp%2==1);
			cur++,temp/=2;
		}
	}
	while(true){	
		for(int i=0;i<=32;i++){
			cnt[i]=0;
			for(int j=1;j<=n;j++)
				if(A[j].num[i]==true) cnt[i]++;
			//printf("debug cnt:%lld\n",cnt[i]); 
		}
		sort(A+1,A+1+n);
		int pos=-1;
		for(int i=32;i>=0;i--)
			if(cnt[i]>=m){
				pos=i;
				break;
			}
		//printf("debug pos:%lld\n",pos);
		if(pos==-1) break;
		ans+=powe(2,pos);
		for(int i=1;i<=n;i++){
			if(A[i].a<powe(2,pos)){
				n=i-1;
				break;
			}
			A[i].a=A[i].a%powe(2,pos);
			memset(A[i].num,false,sizeof(A[i].num));
			int temp=A[i].a,cur=0;
			while(temp){
				A[i].num[cur]=(temp%2==1);
				cur++,temp/=2;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
9：31 a.m. 
位运算，注意到 n 比较大，应该是一道贪心或者线性的

想了 20min+有一点小思路：
9：54 a.m.
先排序，然后看前 m 个位数最少的那个，这就是我们最终答案的位数最大值
例子：
n=4,m=3 
10111
01100
01011
01001
可见我们最终答案最高位应该是 4 位 
然后我们把前一位去掉得到 
0111
1100
1011
1001
重新排个序
1100
1011
1001
0111
取前三个

感觉还是有很多漏洞
1100
1011
1001
从小到大排序之后这里取两个怎么做呢

呃

不妨换个思路，一位一位的搞 
10111
01100
01011
00101
还是取三个，显然最高位不是四位

呃

1 0 1 1 1
0 1 1 0 0
0 1 0 1 1
0 0 1 0 1
1 2 3 2 3 
数组计个数，记录每一位为 1 的个数
可以看到能取三位，于是把前 3 位砍掉再重新排个序再计数 
对了，这里答案累加个 2^(3-1)=4，即 ans+=4 
1 1
1 1
0 1
0 0
2 3
然后现在最高取到最后一位，答案再累加一
然后全砍掉没了，答案就是 5

10：11 a.m. 
时间大概是 30*nlogn ，刚好能过 
我去我想到正解了！！！！！我是天才！！！！！！！！！！ 

10：23 a.m.
打个小补丁，把前面的位砍掉的时候还要砍掉一些不符合条件的数
代码好难… 

10：45 a.m.
打出来了！！！

10：51 a.m.
被 and3.in HACK了呜呜呜  
为啥别的大样例都过了就这个被卡了，这个 m 还等于 2 呢 

注意到 and3.ans为 2^16-2，而我的输出为 2^17，是 pos 求错值了吗 

11：11 a.m.
终于 debug 出来了，%打成-了

时间复杂度：O(logA*NlogN)
难度：yellow~green 
*/
