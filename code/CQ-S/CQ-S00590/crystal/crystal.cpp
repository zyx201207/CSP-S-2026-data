#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cf[500005];
int l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	int ans=1;
	long long p=0;
	l=1;
	for(int i=2;i<=n;i++){
		p+=cf[i]*(i-l);
		if(p>m){
			while(p>m){
				p-=(a[i]-a[l]);
				l++;
			}
		}
		//cout<<l<<' '<<i<<'\n'; 
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

14:32  T1预100
14:38 估完分天塌了、、 、 
14:41 我要上迷惑行为大赏！！！
14:42 搜到的时候你被骗了freopen("crystal.ans","w",stdout);  #include<bits\stdc++.h>
14:43 <think> 我们注意到对于所有在a中的元素操作都只能+1
			> 所以很容易得出大数不能变小
			> 因为m允许有留着不用的，所以一定是向一个a中的值对齐
			> 先sort 
			> 所以是？？？？？？
			> 思考给到滑动窗口 
			> 事已至此先睡觉吧 
[异常的中断]
15:20 完了睡了快一个小时了 
15:20 <think>
 			> 判断为滑动窗口的代码 
			> coding
15:31 T1-AC???
15:31 开始逻辑论证
15:31 T1-AC，Turing保佑！！ 
15:32 老师告诉我1.5h要估分，我估分160+,感觉初二打这个好难啊
15:32 啊啊啊，我不想做T2大阅读啊，我想回去玩zmd
15:33 感觉在屏幕上拉电线（bushi 
15:35 怎么就第一题会啊 
15:37 不是，这数据点变量c卡我一脸
15:44 大阅读太恶心了
15:45 决定做T3
15:45 注意到T3最大接受正解的时间复杂度为n
16:19 1~10先试试,C的B性质没了 
16:36 T3-A-8pts
16:46 T3只有8pts了
哎
16:46 T4读不懂啊，回T2玩会吧
16:55 我认为T2可以Floyd，但是适用于小于200的数据,T2读不懂啊
17:05 哎，我暴力都能挂，无敌了，但是A性质又好像会了
17:15 会滚木
17:37 死了，力竭
估分148PTS（寂寞，没那么高 
freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 freopen("crystal.ans","w",stdout);

 
*/

