#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long cha[500005],tot,ans,m1,head,now_ans,qzh;
/*
5 8
-3 -1 2 2 7
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);//这里改了3 
	freopen("crystal.out","w",stdout);//千万要取注释消喵 
	
	
	scanf("%lld%lld",&n,&m);
	m1=m;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1); 
	for(long long i=2;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];//差值但是正数 
//		printf("%lld ",cha[i]);//zhushi
	}
//	queue<int> q;
	head=1;
	for(long long i=1;i<=n;)//滑动窗口 
	{
		if(tot<=m)//add tail
		{
//			printf("tot%lld+=%lld\n",tot,(now_ans-1)*cha[i]) ;
			tot+=(now_ans-1)*cha[i];
			
//			printf("head=%lld i=%d\n",head,i);
			i++;
			if(tot<=m)//leagal
			{
//				printf("qzh%lld+=%lld\n",qzh,cha[i]) ;
				qzh+=cha[i];
				now_ans++;
//				printf("ans=%lld\n",now_ans);
			}
		}
		else//pop head
		{
//			printf("	tot%lld-=%lld\n",tot,qzh) ;
			tot-=qzh;
//			printf("	qzh%lld-=%lld\n",qzh,cha[head]) ;
			qzh-=cha[head];
			head++;
//			printf("head=%lld i=%d\n",head,i);
			now_ans--;
//			printf("ans=%lld\n",now_ans);
		}
		ans=max(ans,now_ans);
//			printf("\n---------\n");
	}
	printf("%lld",ans);//rp++;
	
	

	return 0;
}
