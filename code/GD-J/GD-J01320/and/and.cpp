#include<iostream>
#include<vector>
using namespace std;
int c[1000000]={};
int d=0;
void aaa(int a,int b,vector<int> e,int f)
{
	if(b==0)
	{
		int g=e[0];
		for(int i=1;i<e.size();i++)
		{
			g=g&e[i];
		}
		if(g>d)d=g;
		return ;
	}
	for(int i=f+1;i<=a;i++)
	{
		e.push_back(c[i]);
		aaa(a,b-1,e,i);
		e.pop_back();
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d",&c[i]);
	}
	vector<int> e;
	aaa(a,b,e,-1);
	printf("%d",d);
	return 0;
}
