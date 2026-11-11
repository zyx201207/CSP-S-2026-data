#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,x,y;
char x2,y2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;//是否在同一车厢
	else cout<<0;
	for(int i=0;i<b.size()-1;i++)
	{
		x+=b[i];
	}
	for(int i=0;i<d.size()-1;i++)
	{
		y+=d[i];
	}
	x2=b[b.size()-1];
	y2=d[d.size()-1];
	if(x==y) cout<<1;//是否是同一排 
	else cout<<0;
	if(x==y&&(x2>='A'&&x2<='C'&&y2>='A'&&y2<='C')||(x2>='D'&&x2<='F'&&y2>='D'&&y2<='F')) cout<<1;//是否是同一排并且是同一连坐 
	else cout<<0;
	if(abs(x2-y2)==1) cout<<1;//是否是相邻 
	else cout<<0;
	return 0;
} 
