#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	freopen("travel.in", "r" , stdin);
	
	freopen("travel.out","w",stdout);
	string e="A ";
	string f="B ";
	string g="C ";
	string h="D ";
	string i="F ";
	if(a==c)
	{
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			if(b[2]==i[0])
			{
				if(d[2]==h[0])cout<<"11"<<endl;
				else cout<<"00"<<endl;
			}
			else if(b[2]==h[0])
			{
				if(d[2]==i[0])cout<<"11"<<endl;
				else cout<<"00"<<endl;
			}
			else if(b[2]==e[0])
			{
				if(d[2]==h[0]||d[2]==i[0])cout<<"00"<<endl;
				else if(d[2]==f[0])cout<<"11"<<endl;
				else cout<<"10"<<endl;
			}
			else if(b[2]==f[0])
			{
				if(d[2]==h[0]||d[2]==i[0])cout<<"00"<<endl;
				cout<<"10"<<endl;
			}
			else
			{
				if(d[2]==h[0]||d[2]==i[0])cout<<"00"<<endl;
				else if(d[2]==f[0])cout<<"11"<<endl;
				else cout<<"10"<<endl;
			}
		}
		else cout<<"000"<<endl; 	
	}
	else cout<<"0000"<<endl;
	return 0;	
} 
