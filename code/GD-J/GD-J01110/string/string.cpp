#include<bits/stdc++.h>
using namespace std;
long long n,z,xbi,xbj,s[200005],f;
long long u[200005];
char v[200005];
long long sum;
long long xx,yy;
char q,w;
void lyb(long long x,long long y)
{
	if(xx>0)//上一次x还有剩 
	{
		if(u[y]>xx)//这一次的右边的数量大于剩下来的数量 
		{
			if(v[y]!=q) sum+=xx;//如果字符不等于 就相加 
			u[y]-=xx,xx=0;//u的数量就要相对应减少 xx变成0 
		}
		else//右边数量还是小于剩下来的数量 
		{
			if(v[y]!=q) sum+=u[y];//字符还是不等于 就相加 
			xx-=u[y],u[y]=0,xbj--;//xx减去u[y]个数量，u[y]就是0，没必要判断u[x]和u[y]直接退出 
			return ;//退出 
		}
	}
	if(yy>0)//上一次y还有剩 
	{
		if(u[x]>yy)//这一次左边的数量大于剩下来的数量 
		{
			if(v[x]!=w) sum+=yy;//如果字符不等于 就相加 
			u[x]-=yy,yy=0;//u的数量就要相对应减少 yy变成0 
		}
		else//左边数量还是小于剩下来的数量 
		{
			if(v[x]!=w) sum+=u[x];//字符还是不等于 就相加 
			yy-=u[x],u[x]=0,xbi++;//yy减去u[x]个数量，u[x]就是0，没必要判断u[x]和u[y]直接退出 
			return ;//退出 
		}
	}
	//到了这里要么是x y本身就是0
	//要么执行完后xx=0 yy=0不等于0的已经退出了 
	if(u[x]>u[y])//左边数量大于右边数量 
	{
		if(v[x]!=v[y]) sum+=u[y];//字符不相等 相加最小值 
		xx=u[x]-u[y],q=v[x];//不管怎么样 x肯定会剩下来 算出剩下来的个数，字符变化
		xbj--; 
	}
	else if(u[x]<u[y])//左边数量小于右边数量 
	{
		if(v[x]!=v[y]) sum+=u[x];//字符不相等 相加最小值 
		yy=u[y]-u[x],w=v[y];//赋值多出来的yy数量，字符变化 
		xbi++;
	}
	else 
	{
		if(v[x]!=v[y]) sum+=u[x];//相等直接判断字符是否相等
		xbi++,xbj--;//相加 
	}
	return ;
}
int main()
{
	freopen("string.in","r",stdin);//改 
	freopen("string.out","w",stdout);//改 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>u[i]>>v[i],z+=u[i],s[i]=s[i-1]+u[i];
	for(int i=1;i<=n;i++)
		if(s[i]>=(z/2+z%2)){f=i;break;}
	xbi=1,xbj=n;		
	while(1)
	{
		lyb(xbi,xbj);
		if(xbj<=xbi) break;	
	}
	if(xbj<f) z=1;
	else z=0;
	cout<<max(sum-z,0LL);
	
	return 0;	
} 
