#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,f=1,f2=1,f3=1,ans=0;
int cnt1=0,cnt2=0,cnt3=0;
int a[200010]={0};
int k[31]={0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1,j=2;i<=30;i++)
	{
		k[i]=j;j*=2;
	}
	cin>>n>>m;
	int mx=0,mxpos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>mx){mx=a[i];mxpos=i;}
		if(a[i]!=i-1)f=0;
		if(f2)
		{
			for(int j=1;j<=30;j++)
			{
				if(a[i]==k[j]-1){f2=1;break;}
				else f2=0;
			}
		}
		if(a[i]>=4)f3=0;
		if(a[i]==1)cnt1++;
		if(a[i]==2)cnt2++;
		if(a[i]==3)cnt3++;
	}
	if(m==1)
	{
		cout<<mx;return 0;
	}
	if(m==2)//反正n<=2000 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)ans=max(ans,a[j]&a[i]);
			}
		}
		cout<<ans;return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans;return 0;
	}
	if(m==n-1)//1101 & 10 < 1101 & 1
	{
		
	}
	if(f2)//性质A 
	{
		sort(a+1,a+1+n);ans=a[n];
		for(int i=n;i>n-m;i--)ans&=a[i];
		cout<<ans;return 0;
	}
	if(f)//性质B 
	{
		
	}
	if(f3)//a[i]<4
	{
		if(cnt3>=m)cout<<3;
		else if(cnt2>=(m-cnt3))cout<<2;
		else if(cnt1>=(m-cnt3))cout<<1;
		else cout<<0;//万不得已 万念俱灰（bushi 
		return 0;
	}
	bool vis[200010]={0};ans=mx;
	int pos=0;
	vis[mxpos]=1;
	for(int i=2;i<=m;i++)
	{
		mx=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])continue;
			if((ans&a[j])>mx)
			{
				mx=ans&a[j];pos=j;
			}
		}
		ans=mx;
		vis[pos]=1;
	}
	cout<<ans;
	
	return 0;
}
//65
/*
完全（并非 不会做啊啊 

要开始了哟~~
欢迎回来~
请选择要替换的旅行伙伴~~
let's 够~~~~~~

笑点解析：刚开始做题的时候忘了文件读写怎么写了，测试的时候没有输出还以为是文件读写的问题，结果发现是代码没写输出
要是爆0了就哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈呜呜 

丸辣今年一等奖分数线肯定超过了260
自嘲：！？区是的003到拿没没拿到300的是区？！（首先我只是有拿到300的愿望其次这只是自嘲没说任何人最后这不影响RP祝你们RP++） 
事已至此，先吃个汉堡吧。——《止战之殇》 

我就是b站的 霏吔faye ^v^ 

能上迷惑行为大赏非常开心，在此感谢这篇迷惑行为大赏的作者，辛苦了~~ 

sto                                                     orz
sto                      ##########                     orz
sto                     #          #                    orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                     #          #                    orz
sto                      ##########                     orz
sto                                                     orz
sto                      ##########                     orz
sto                     #          #                    orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                     #          #                    orz
sto                      ##########                     orz
sto                                                     orz
sto                    #############                    orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    ############                     orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                    #                                orz
sto                                                     orz

信息竞赛人特有的神秘仪式 
什么皇帝登基（ 

*/
