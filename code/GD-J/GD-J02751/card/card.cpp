#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=3e5+1;
int n,m,a[M],ans[M]={0};
signed main()
{	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{	int dq[M],pt=0;
		bool pd[M];
		memset(pd,0,sizeof(pd));
		for(int j=i;j<=n;j++)
		{	if(pd[a[j]])
			{	pd[a[j]]=0;
				while(dq[pt]!=a[j])
					pd[dq[pt]]=0,pt--;
				pd[dq[pt]]=0,pt--;
			}
			pt++;
			dq[pt]=a[j];
			pd[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
			if(pd[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
//打个暴力吧
//话说这题card4.ans怎么怪怪的 刚输出时吓我一跳 
//I Love CCF!
//T1 100pts + T2 100pts + T3 50pts + T4 48pts = 298pts ?
//I donno maybe 1=
//GDOI2026 rk19学长XY_eleven保佑J S 1=! 
//last change: 11:47 ;count down:10:20
