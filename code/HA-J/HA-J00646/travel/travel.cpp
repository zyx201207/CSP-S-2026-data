#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int ans1=0,ans2=0,ans3=0,ans4=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		ans1=1;
	}
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1])
	{
		ans2=1;
	}
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&((c2[2]<='C'&&c2[2]>='A'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]<='F'&&c2[2]>='D'&&c4[2]>='D'&&c4[2]<='F')))
	{
		ans3=1;
	}
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&(c2[2]+1==c4[2]||c2[2]-1==c4[2])&&((c2[2]<='C'&&c2[2]>='A'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]<='F'&&c2[2]>='D'&&c4[2]>='D'&&c4[2]<='F')))
	{
		ans4=1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}