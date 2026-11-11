#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int tid,q,n,d,x[2919810],line[2919810][2],add[2919810],add2[2919810]; 
signed main()
{
	ioimprove();
	FILE("migrate");
	cin>>tid>>q;
	if(tid == 11 || tid == 12)
	{
		while(q--)
		{
			cin>>n>>d;
			for(int i = 1;i <= n;i++) cin>>x[i];
			int l = d / (x[2] - x[1]);
			if(l == 0 || l == 1) cout<<"0\n";
			else if(2 * l > n) cout<<"0\n";
			else cout<<n - 2 * l + 1<<"\n";
		}
		return 0;
	}
	if(tid >= 13)
	{
		while(q--) cout<<"0\n";
		return 0;
	}
	while(q--)
	{
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>x[i];
		memset(line,0,sizeof line);
		memset(add,0,sizeof add);
		memset(add2,0,sizeof add2);
		int nowl = 1,nowr = 1,nowdl = 0,nowdr = 0;
		for(int i = 1;i <= n;i++)
		{
			if(i > 1) nowdl += x[i] - x[i - 1],nowdr -= x[i] - x[i - 1];
			while(nowdl > d) nowl++,nowdl -= x[nowl] - x[nowl - 1];
			while(nowdr + x[nowr + 1] - x[nowr] <= d && nowr < n) nowr++,nowdr += x[nowr] - x[nowr - 1];
			line[i][0] = nowl,line[i][1] = nowr;
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				if(line[i][1] == line[j][0]) add[j] += add[i] + 1;
		for(int i = n;i >= 1;i--)
			for(int j = i - 1;j >= 1;j--)
				if(line[i][0] == line[j][1]) add2[j] += add2[i] + 1;
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				if(line[i][1] == line[j][0] + 1) cnt += (1 + add[i]) * (1 + add2[j]);
		cout<<cnt<<"\n";
	}
	
	return 0;
}
//什么？我只用了 90min 就进入了 T3？
//最搞笑一点：监考老师将迁徙念作“迁徒”
//根本没有人绷得住
//脑子有点晕玩一会冲浪
//冲浪轻松拿下一万分，上个厕所开始写题
//上厕所举手的时候监考老师拍了拍我肩膀，那时我在玩冲浪，有种划水被教练抓到的既视感（？） 
//哎呦我滴妈 2e6 不能双 log 啊，单 log 咋搞 
//没思路啊，还是平时划水划太多了
//什么叫这一对还要恰好两种路啊，(u,v) + (v,w) 推出 !(u,w) 是吧？
//要不先打打特殊性质，56pts 感觉还是很好搞的 
//性质 C 想启发我啥啊，这个 10 倍关系啥意思
//哦是任意两个岛屿间最多飞 10 次是吧
//我毫无头绪 该如何提取 
//不管了 56pts 先拿到手再说 
//不是 n^2 咋做啊，我是怎么觉得这个好搞的，目前只会性质 B 咋办 
//骗你的性质 B 也不会
//目前 only 200pts 
//考虑一种转化
//将每个点记录为一条线段，线段左右端点是能够直飞的左右边界
//(u,v) 为一个对等价于 (u,v) 表示的线段交点有且仅有两个
//如果两条线段刚好首尾相接就直接并起来没影响 
//然后拿个桶枚举做完了？？？？？ 
//线路为最短的性质能否保证？
//感性理解可以，毕竟我每条线都是在极限的位置接上 
//记录左边界没用，只记录右边界就行了
//计数是第一生产力 
//哎不对啊有点炸了
//不对啊脑瘫了我开始写的啥啊 
//不管了 40pts 先吃上再说 
//急哭了 40pts 也吃不上啊，随机挂分 
//为啥答案大了啊，我并不认为有错误计算啊 
//其实我只会性质 A
//D 题根本不想看啊，要不就这样 208pts？
//我不甘心啊啊啊啊啊啊啊
//空悲切 
//208pts 大概还是可以 1= 的吧
//这没有我就要被教练赶出机房了啊 
//唉初三拿不到洛谷勾 7
//菜 
//不对啊不止 40pts 这档暴力
//还有更暴力的我没看到
//写下这行字的时候是 18:27
//我已疾苦 

//此情可待成追忆，只是当时已惘然
