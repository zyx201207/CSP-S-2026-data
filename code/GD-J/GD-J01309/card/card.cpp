#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,m,cnt[N],nxt[N],lst[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(nxt,0,sizeof(nxt));
	memset(lst,0,sizeof(lst));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)nxt[lst[a[i]]]=i,lst[a[i]]=i;
	for(int i=1;i<=n;i++)cnt[i]=1;
	for(int i=1;i<=m;i++)ans[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i])
		{
			cnt[nxt[i]]+=cnt[i];
			cnt[i]=0;
		}
		else
		{
			ans[a[i]]+=cnt[i];
			cnt[i+1]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
/*
第一题发现并没有E这个座位号，还好发现的及时，要不然第一题就挂了。 
第二题瞪眼瞪了好久，后来想到做法才觉得自己像弱智，双指针扫一遍就可以了 
第三题感觉比第二题简单，可能是因为之前做过的原因，基本上思考的时间不到两分钟，也没有调（会不会有问题？） 
第四题感觉难了点，估计难度在绿吧，用图的方法解决了，大样例4的ans文件打开之后全是乱码，对不了一点，感觉还是一个有特殊性质的大样例，有点可惜。 
总体来讲题目没有什么难度，相比于去年的题变简单了，这次说不定可以AK（！？狂狂？！）。
10:20做完所有题，去年我拿了240分，今年感觉非常不一样，感觉题变简单了。今年是在万圣节考的，解压密码是Trick||Treat!，居然还有逻辑运算。去年好像是上善若水吧 
10:30我的知情同意书监考员忘收了，现在才收的 
10:56四道题的对拍都打完了，第四题发现自己题目读错了，然后代码里面王嘉逸了，正好就弥补了读错题的问题。感觉我的对拍文件在我不看他的时候不会工作 
11:15话说在代码里面打一万个换行符会炸吗？ 
11:25对拍已经对了俩小时了，严肃思考是否需要给对拍写对拍 
11:34看了眼checker，第三题从9:31就没有修改过了，意思是我用一个小时做了前三题，一个小时做了最后一题，第三题还从来没改过 
11:34第二题freopen差点被我注释掉 






fishy祭天，法力无边 
*/ 
