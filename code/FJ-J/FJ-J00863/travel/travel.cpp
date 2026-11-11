#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,x2,y1,y2;
	char c1,c2;
	scanf("%d%d%c%d%d%c",&x1,&y1,&c1,&x2,&y2,&c2);
	if(x1==x2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(y1==y2)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	int flag;
	if(c1<='C'&&c2<='C')flag=1;
	else if(c1>='D' && c2>='D')flag=11;
	else flag=0;
	cout<<flag;
	if(flag==1&&abs(c1-c2)==1)cout<<"1";
	else cout<<"0";
	return 0;
}
