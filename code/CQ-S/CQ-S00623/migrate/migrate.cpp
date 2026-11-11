#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define int long long
#define INF 1000000000
namespace lzz
{
	int C,T; 
	int n,d,x[N],t[N];
	int mn[N],mx[N],pre[N],nxt[N]; 
	int f[N],g[N],op[N],ans;//前面已该点为关键点的中间有一个神秘点的点数量/没有关键点 
	void clr()
	{
		ans=0;
		for(int i=0;i<=n+1;i++)f[i]=g[i]=mx[i]=op[i]=nxt[i]=t[i]=pre[i]=0,mn[i]=INF;
	}
	int main()
	{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>C>>T;
		while(T--)
		{
			clr(),cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			nxt[n]=n; for(int i=n-1;i>=1;i--){nxt[i]=nxt[i+1]; while(x[nxt[i]]-x[i]>d)nxt[i]--;}
			pre[0]=1;
			for(int i=1;i<=n;i++)
			{
				pre[i]=pre[i-1]; while(x[i]-x[pre[i]]>d)pre[i]++;
				int j=pre[i];//j为最远的能到i的点
				op[i]=(nxt[j-1]<(i-1)),pre[i]=j;
				ans+=f[j];//最后一步不合法,加入前面有恰好一个神秘点的
//				cout<<"!!!"<<ans<<" "<<j<<" "<<f[j]<<endl;
				for(int k=j+1;k<=min(i-1,j+1);k++)
				{
					ans+=op[k]*g[k]+(!op[k])*max(0ll,(pre[k]!=0)*(mx[k]-pre[k]+1));//cout<<"##"<<k<<" "<<op[k]<<" "<<g[k]<<" "<<mx[k]<<" "<<pre[k]<<endl;//计算上一步在k的合法方案(此时k是一个神秘点)
//					if(T==10)
//					{
//						if(!op[k])cout<<"!!"<<i<<" "<<k<<" "<<(!op[k])*max(0ll,(pre[k]!=0)*(mx[k]-pre[k]+1))<<" "<<pre[k]<<" "<<mx[k]<<" "<<(g[k]<(!op[k])*max(0ll,(pre[k]!=0)*(mx[k]-pre[k]+1)))<<endl;
//					}
				}
				//此时还要计算一步就走到k的,只不过贡献为0 
				g[nxt[i]]++; mx[nxt[i]]=max(mx[nxt[i]],i); //if(mn[nxt[i]]==INF)mn[nxt[i]]=i;
				if((nxt[i-1]==nxt[i])&&((i==1)||(nxt[i-2]!=nxt[i])))f[nxt[i]]+=g[i]; else f[nxt[i]]+=f[i],g[nxt[i]]+=g[i];//不能有不相邻的神秘点 
//				if(T==10)cout<<"###"<<i<<" "<<ans<<endl;
			}cout<<ans<<'\n';
		}

		return 0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000

1

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

4
*/
