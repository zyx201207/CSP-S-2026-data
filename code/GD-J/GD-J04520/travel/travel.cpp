#include<bits/stdc++.h>
using std::cin;
int a,b,a1,b1;
char c1,c2;
void p(int x)
{
	if(x==0)
	{
		printf("0");
	}
	else
	{
		printf("1");
	}
}
int ys1[1005],ys2[1005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ys1['A']=1;
	ys1['B']=1;
	ys1['C']=1;
	ys1['D']=2;
	ys1['F']=2;
	ys2['A']=1;
	ys2['B']=2;
	ys2['C']=3;
	ys2['D']=4;
	ys2['F']=5;
	cin>>a>>a1>>c1>>b>>b1>>c2;
	p(a==b);
	p(a==b&&a1==b1);
	p(a==b&&a1==b1&&ys1[c1]==ys1[c2]);
	p(a==b&&a1==b1&&ys1[c1]==ys1[c2]&&std::abs(ys2[c1]-ys2[c2])==1);//µÝ½ø
	return 0;
}
