#include<bits/stdc++.h>
using namespace std;
	int a[1000000],ans[1000000];
		bool shuzi[1000000];
int main()
{
	int n,m;
	cin>>n>>m;
//	int a[1000000],ans[1000000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	queue <int> duilie;
	for(int i=1;i<=n;i++)
	{
		duilie.push(a[i]);
	}
	int eee=0;
	while(!duilie.empty())
	{
		stack <int> zhan;
	//	bool shuzi[1000000];
		for(int i=1;i<=n-eee;i++)
		{
			int a=duilie.front();
			duilie.pop();
			duilie.push(a);
			if(shuzi[a]==1)
			{
				while(1)
				{
					zhan.pop();
					if(zhan.top()==a)
					{
						break;
					}
				}
			}
			shuzi[a]=1;
			//cout<<zhan.pop();
		}
		while(!zhan.empty())
		{
			ans[zhan.top()]++;
			zhan.pop();
		}
		eee++;
		duilie.pop();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
//	666Ö±½Ó±©Á¦£¡£¡£¡ ©±  ©µ©±  ©µ©±  ©µ©±  ©µ
//  oh no!            ©¦A ©¦©¦B ©¦©¦C ©¦©¦D ©¦ 
//	3221226356!!!!!!  ©¹  ©½©¹  ©½©¹  ©½©¹  ©½  
}
