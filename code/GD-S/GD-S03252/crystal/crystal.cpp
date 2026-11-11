#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500001];
ll ans=1;
ll qzh[500001]; 
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i,mid;
		while(1)
		{
			mid=(r+l)/2;
			//cout<<mid<<' '<<a[i]*(i-mid+1)<<' '<<(qzh[i]-qzh[mid-1])<<'\n';
			if(l==r) break;
			if(a[i]*(i-mid+1)-(qzh[i]-qzh[mid-1])>m) l=mid+1;
			else r=mid;
		}
		//cout<<"find "<<i<<" to "<<mid<<'\n';
		//cout<<"----------------------\n";
		ans=max(ans,i-mid+1);
	}
	cout<<ans;
	return 0;
}
/*
T1感觉看起来就是一个贪心
也许可以暴力枚举？最坏大概就是nlogn的样子
从小到大排序，枚举假设要变成哪一个
注意到直接暴力枚举查找会爆，考虑加一个二分 
OK思路正确大样例通过
现在时间15:00
我去怎么T1用了半个小时 
*/
/*
注意不要变成： 
//freopen("
froepen
freopen("crystal.in","w",stdin);
	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
*/
/*
初级监狱啥时候升级的电脑我怎么不知道？
哎你就这么弄吧我一毕业你就开始升级
这辈子有了
QwQ
关注Luogu xiaobiru7302_1（uid：975426）谢谢喵 
*/
/*
8(=D) <- 天依啥笑
猫猫！
（话说我记得原来初中也有猫来着怎么这次好像没看到）
高中的猫倒是挺多 
（不会日语跳过前奏）
叮咚（叮叮咚咚）收到总部命令
前往蓝星 调查人类习性
惺忪（惺惺忪忪）困倦还未清理（猫猫打哈欠）
披上伪装 开始秘密潜行
这独~来独往的身影
和那目~中无人的神情
这无~法无天的行径
似曾相识（难道说~oh！） 
（不会日语跳过）
说白了 泡面、辣条、充电线
它们本质上就是 罐头、猫条、毛线球
无论说的多上流
猫咪就是喜欢装模做样，大模大样，装的像模像样 
觉得我们多高尚它们多低档
到头来还不是一模一样 
这独~来独往的身影
和那目~中无人的神情
这无~法无天的行径
似曾相识
（跳过尾端） 
*/
/*
刚刚突然回来想用这题试试我会不会用NOI linux来着，结果发现完全不会编译运行这辈子有了 
*/
/*
完蛋了这可能是我唯一会的一题再这里多写点东西吧
我感觉这次不太好怎么有两道图论
不如改一道博弈论出来（划掉 
然后特别建议CCF能不能以后考虑考虑再每一题里面放点随机输入数据生成器（
当然好像没什么用要对拍的自己会写不对拍的也用不着
我知道了可以搞点附加题 比如说IOI题目（划掉 做出来可以加INF分
突然意识到不让写歌词其实是怕选手们写完歌词超过100KB然后导致程序上传不上去（确信）
NOI linux 能不能出点好用的编辑器
搞一个类似Dev-C++这样对新手友好点的
这样不会用NOI linux的选手们也能够在NOI linux里面测试自己的代码嘛
要不然神秘地方报错了都不知道
解压密码Oct31==Dec25?是打算吧CSP-S提升到NOIP同等难度吗？
然后让NOIP真的变成NOI Plus？（bushi
哎这里写太多了我得换题写 
这注释都占了文件总长度约9/13了（绷 
*/
