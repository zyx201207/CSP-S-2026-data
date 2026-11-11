#include<bits/stdc++.h>
using namespace std;
int xianga,weia,xiangb,weib,seata,seatb;
string b,d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in" ,"r",stdin );
	freopen("travel.out","w",stdout);
	cin>>xianga>>b>>xiangb>>d;
	seata=b[2]-'A'+1; b[2]=' ';
	seatb=d[2]-'A'+1; d[2]=' ';
	weia=stoi(b);
	weib=stoi(d);
	//cout<<xianga<<" "<<weia<<" "<<seata<<" "<<xiangb<<" "<<weib<<" "<<seatb<<"\n";
	if(xianga==xiangb) 
	{
		cout<<"1";
		if(weia==weib)
		{
			cout<<"1";
			if((seata<=3&&seatb<=3)||(seata>=4&&seatb>=4))
			{
				cout<<"1";
				if(seata-seatb==1||seata-seatb==-1)
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
