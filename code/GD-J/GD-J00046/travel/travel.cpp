#include<bits/stdc++.h>
using namespace std;
string sa,sb,sc,sd;
long long ax,ah,al,bx,bh,bl;
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	ax=(sa[0]-'0')*10+sa[1]-'0';
	ah=(sb[0]-'0')*10+sb[1]-'0';
	al=sb[2]-'A'+1;
	if(al==6) al=5;
	bx=(sc[0]-'0')*10+sc[1]-'0';
	bh=(sd[0]-'0')*10+sd[1]-'0';
	bl=sd[2]-'A'+1;
	if(bl==6) bl=5;
//	cout<<ax<<" "<<ah<<" "<<al<<"\n";
//	cout<<bx<<" "<<bh<<" "<<bl;
	if(ax==bx)
	{
		cout<<"1";
		if(ah==bh)
		{
			cout<<"1";
			if((al>=1&&al<=3&&bl>=1&&bl<=3)||(al>=4&&al<=5&&bl>=4&&bl<=5))
			{
				cout<<"1";
				if(abs(al-bl)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
