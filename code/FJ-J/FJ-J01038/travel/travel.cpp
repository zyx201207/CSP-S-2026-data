#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string x1,y1,x2,y2;
int ans[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>y1>>x2>>y2;
	ans[0]=(x1==x2);
	ans[1]=(ans[0]&&(y1[0]==y2[0])&&(y1[1]==y2[1]));
	ans[2]=(ans[1]&&((y1[2]<='C'&&y2[2]<='C')||(y1[2]>'C'&&y2[2]>'C')));
	ans[3]=(ans[2]&&(abs(int(y1[2]-y2[2]))==1));
	printf("%d%d%d%d\n",ans[0],ans[1],ans[2],ans[3]);
	return 0;
}
