//W
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	bool g=0,h=0,i=0,j=0;
	cin>>a>>b>>c>>d;
	if(a==c)g=1;
	if(b[0]==d[0]&&b[1]==d[1]&&g)h=1;
	if(((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C'))&&h)i=1;
	if(abs(b[2]-d[2])==1&&i)j=1;
	if(b[2]+d[2]=='D'+'F'&&i)j=1;
	cout<<g<<h<<i<<j;
	return 0;
}
//luogu uid:1770324 
//不知道有没有人做迷惑行为大赏 
//不过还是想开玩笑
//来场说走就走的旅行~
//                  ----《给你寄的信》  
//S
