#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string as,bs;
	cin>>a>>as>>b>>bs;
	if(a==b)
	{
		cout<<"1";
	
		if(as[0]==bs[0] and as[1]==bs[1])
		{
			cout<<"1";
			if('A'<=as[2] and 'C'>=as[2] and 'A'<=bs[2] and 'C'>=bs[2]) 
			{
				cout<<"1";
				if(abs(as[2]-bs[2])==1)cout<<"1";
				else cout<<"0";
			}
			else if('A'<=as[2] and 'B'>=as[2] and 'A'<=bs[2] and 'B'>=bs[2])
			{
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
 } 
