#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int sta1=0,sta2=0,sta3=0,sta4=0,sta5=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) sta1=1;
	if(sta1==1||s1[0]==s2[0]||s1[1]==s2[1]) sta2=1;
	sta3=1;
	 sta4=1;

	cout<<sta1<<sta2<<sta3<<sta4<<endl;
	return 0;
}

