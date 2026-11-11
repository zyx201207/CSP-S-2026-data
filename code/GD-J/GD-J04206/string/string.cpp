#include <iostream>
using namespace std;
using ll=long long ;
long long n;
long long a1[200005];
char c1[200005];
long long a[200005];
char c[200005];
long long xb;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	//#####
	ll sm=0;
	//#####
	for(long long i=1;i<=n;i++)
	{
		cin>>a1[i]>>c1[i];
		sm+=a1[i];
	}
	a[1]=a1[1];c[1]=c1[1];
	xb=1;
	for(long long i=2;i<=n;i++)
	{
		if(c[xb]==c1[i])
		{
			a[xb]+=a1[i];
		}
		else
		{
			xb++;
			a[xb]=a1[i];c[xb]=c1[i];
		}
	}
//	for(long long i=1;i<=xb;i++)
//	{
//		cout<<a[i]<<' '<<c[i]<<'\n';
//	}

    //处理过程 

	long long ls=1,rs=xb,lp=1,rp=a[xb];
	long long lpos=1,rpos=sm;
	//（可保证循环过程中lpos始终==rpos） 
	
	//0. 处理最开始的
	
	if(c[ls]!=c[rs])
	{
		ans++;
	} 
	
	for(;lpos<=rpos;)
	{
		//计算前进距离 
		ll ldis=a[ls]-lp;
		ll rdis=rp-1;
		ll mn=min(ldis,rdis);
		ll fddis;
		bool flag;flag=0;
		if(mn==0)//当前段为0 
		{
			fddis=1;//往前前进一步 
		}
		else
		{
			fddis=mn;
		}
		//处理前进 
		//1. 检查中间位置 
		if(lpos+fddis>rpos-fddis)//已经要到中间 
		{
			//那么将目的地设为中间
			if(sm%2==1)//是奇数（有一个中心点） 
			{
				fddis=(sm>>1)+1-lpos;//去中心 
			}
			else
			{
				fddis=(sm>>1)-lpos;//两边相遇 
			}
			flag=1;//执行完本趟循环就结束 
		}
		//2. 处理前进
		//2.1. 当前段为0那么整体前进一步
		if(mn==0)
		{
			char x,y;//比较左边或右边的字符是否相等 
			if(ldis==0)//左边需要新开
			{
				ls++;
				lp=1;
				lpos++;
				
			} 
			else//左边不需要新开 
			{
				lp++;
				lpos++; 
			}
			x=c[ls];
			if(rdis==0)
			{
				rs--;
				rp=a[rs];
				rpos--;
			}
			else
			{
				rp--;
				rpos--;
			}
			y=c[rs];
			if(x!=y)
			{
				ans++;
			}
		} 
		//2.2. 左右都不为0那么按fddis前进 
		else
		{
			lp+=fddis;
			lpos+=fddis;
			
			rp-=fddis;
			rpos-=fddis;
			
			if(c[ls]!=c[rs])
			{
				ans+=fddis;
			}
		}
		
		//3. 检查flag
		
		if(flag)
		{
			break;
		 } 
	}
	cout<<ans<<'\n';
	
	return 0;
}
