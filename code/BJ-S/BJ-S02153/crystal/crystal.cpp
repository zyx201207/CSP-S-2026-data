#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],d[N],ans=-1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]) 
		{
			ans++;
			continue;
		}
		int cnt=0,res=0;
		for(int j=1;j<i;j++)
		{
			d[j]=a[i]-a[j];
		}
		sort(d+1,d+i-1+1);
		while(1)
		{
			if(cnt==i-1||res+d[cnt+1]>m) break;
			cnt++;
			res+=d[cnt];
		}
		if(cnt+1>ans) ans=cnt+1;
		else break;
	}
	cout<<ans;
	return 0;
}

/*
 考试前一天发高烧。。。
 本来最有希望的J也没考好 一直在发烧 情绪也特别不稳定 TvT
 （T2想出正解了但细节上错了 最后没办法了交了个暴力 TvT）
 虽然S本来也没抱希望 TvT
 马上又期中了 因为生病两天都一点都没有学习 特别特别焦虑 TvT 
 竞赛班的大家怎么都这么聪明这么厉害 弄得我特别自卑特别害怕跟不上 TvT
 真的真的好想哭 TvT（其实现在正坐在S考场上抹眼泪 TvT）
 信息怎么这么难学 不知道自己还会不会有明年的CSP TvT
 事已至此 祝自己期中考试加油 TvT
 最后在此祝ssf机房里的大家 RP++ RK-- 成功直升 实现梦想！
 最重要的 天天开心 身体健康！（发烧好难受的 TvT）
 
		——2026.10.31 现在头疼的不想看题 手也不知道为什么特别凉 TvT


 后记——再次看到这段话的你 期中有没有考好呀 QwQ
*/
