#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	printf("%d",c1==c3);
	printf("%d",c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]);
	printf("%d",c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&((c2[2]<'D'&&c4[2]<'D')||(c2[2]>='D'&&c4[2]>='D')));
	printf("%d",c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&((c2[2]<'D'&&c4[2]<'D')||(c2[2]>='D'&&c4[2]>='D'))&&abs(c2[2]-c4[2])==1);
	return 0;
}
