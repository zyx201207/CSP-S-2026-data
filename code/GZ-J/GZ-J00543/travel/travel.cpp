//GZ-J00543 贵阳市第十八中学 王相宇  
#include<bits/stdc++.h>
using namespace std;
string anum,bnum,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>anum>>a>>bnum>>b;
	string ax=a.substr(0,2),ay=a.substr(2),bx=b.substr(0,2),by=b.substr(2);
	if(anum==bnum)cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(ax==bx)cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(ay=="A"&&by=="B")cout<<"1";
	else if(ay=="A"&&by=="C")cout<<"1";
	else if(ay=="B"&&by=="A")cout<<"1";
	else if(ay=="B"&&by=="C")cout<<"1";
	else if(ay=="C"&&by=="B")cout<<"1";
	else if(ay=="C"&&by=="A")cout<<"1";
	else if(ay=="D"&&by=="F")cout<<"1";
	else if(ay=="F"&&by=="D")cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(ay=="A"&&by=="B")cout<<"1";
	else if(ay=="B"&&by=="A")cout<<"1";
	else if(ay=="B"&&by=="C")cout<<"1";
	else if(ay=="C"&&by=="B")cout<<"1";
	else if(ay=="D"&&by=="F")cout<<"1";
	else if(ay=="F"&&by=="D")cout<<"1";
	else cout<<"0";
	return 0;
}

    
