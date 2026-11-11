#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],t[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)//输入 
	{
		cin>>a[i];			
	}	
	for(int i=1;i<=n;i++)//第i局 
	{
		for(int j=i;j<=n;j++)//第i局剩下的卡牌 
		{
			b[j]=a[j];//剩下的卡牌  
			c[b[j]]++;//剩下的卡牌出现次数  
			if(c[b[j]]>1)//当剩下的卡牌出现次数>1 时  
			{
				for(int z=1;z<=j;z++)
				{
					b[z]=0;//清空，把最后出现的一张卡牌放在 b[j] 
					c[z]=0;
				}
				b[1]=a[j];
			}
		}
		for(int w=1;w<=n;w++)
		{
			if(b[w]==0)
			{
				continue;
			}
			else
			{
			t[b[i]]++;//当前数字的出现次数 
			b[i]=0;
			}
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(t[i]>0)
		cout<<t[i]<<" ";
	}
	return 0;
}
