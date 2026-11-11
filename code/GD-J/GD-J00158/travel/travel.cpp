#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string z1,z2,p1,p2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	z1=s1[0]+s1[1];
	z2=s2[0]+s2[1];
	p1=s1[2];
	p2=s2[2];
	//cout<<s1<<" "<<s2<<" "<<z1<<" "<<z2<<" "<<p1<<" "<<p2<<"\n"; 
	if(c1==c2)
	{
		cout<<"1";
		if(z1==z2)
		{
			cout<<"1";
			if(p1=="F"&&p2=="D")
				cout<<"11";
			else if(p1=="D"&&p2=="F")
				cout<<"11";//1
			else if(p1=="C"&&p2=="B")
				cout<<"11";
			else if(p1=="B"&&p2=="C")
				cout<<"11";//2
			else if(p1=="A"&&p2=="B")
				cout<<"11";
			else if(p1=="B"&&p2=="A")
				cout<<"11"; //3
			else if(p1=="A"&&p2=="C")
				cout<<"10";
			else if(p1=="C"&&p2=="A")
				cout<<"10";//4
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
