#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	register char ch=getchar();
	register int res=0;
	while(ch<'0'||'9'<ch)
		ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res;
}
int n,m,a[500010],pre[500010],tmp[300010],res[300010];
bool flag[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
		pre[i]=tmp[a[i]];
		tmp[a[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//		cout<<i<<": "<<pre[i]<<" "<<nxt[i]<<"\n";
	for(int T=1;T<=n;T++)
	{
		memset(flag,true,sizeof flag);
		memset(tmp,0,sizeof tmp);//前者用于记录下标，后者用于记录出现个数 
		for(register int i=1;i<T;i++)
			flag[i]=false;
		for(register int i=T;i<=n;i++)
		{
			tmp[a[i]]++;
			register int ppre=pre[i];
			while(ppre>=T&&flag[ppre]==false)
				ppre=pre[ppre];
//			cout<<"For "<<i<<": ppre="<<ppre<<"\n";
			if(ppre>=T)
			{
//				cout<<"Delete ";
				for(register int j=ppre;j<i;j++)
				{
					if(!flag[j])
						continue;
//					cout<<"a["<<j<<"]="<<a[j]<<";";
					flag[j]=false;
					tmp[a[j]]--;
				}
//				cout<<"\n";
			}
//			for(int i=1;i<=m;i++)
//				cout<<tmp[i]<<" ";
//			cout<<"\n";
		}
//		for(register int i=1;i<=m;i++)
//			printf("%d ",tmp[i]);
//		cout<<"\n===\n";
		for(register int i=1;i<=m;i++)
			if(tmp[i]) res[i]++;
	}
	for(register int i=1;i<=m;i++)
		printf("%d ",res[i]);
	return 0;
}
/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1
*/

