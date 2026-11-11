#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ar,br,ax,bx;
	cin>>ar>>br>>ax>>bx;
	if (ar==ax) cout<<1;
	else
	{ 
		cout<<0<<0<<0<<0;
		return 0;
	}
	string twoR,twoX;
	for (int i=0;i<2;i++)
	{
		twoR+=br[i];
		twoX+=bx[i];
	}
	if (twoR==twoX) cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0; 
	}
	string threeR,threeX;
	for (int i=2;i<br.size();i++)
	{
		threeR+=br[i];
		threeX+=bx[i];
	} 
	if ((threeR=="A" && threeX=="B") || (threeR=="B" && threeX=="C") || (threeR=="B" && threeX=="A") || (threeR=="C" && threeX=="B") || (threeR=="D" && threeX=="F") || (threeR=="F" && threeX=="D")) cout<<1<<1;
	else if ((threeR=="A" && threeX=="C") || (threeR=="C" && threeX=="A")) cout<<1<<0;
	else cout<<0<<0;
	return 0;
}
