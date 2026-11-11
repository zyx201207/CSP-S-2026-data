#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b[100],d[100];
	cin>>a>>c>>b[100]>>d[100];
	//a第一个车厢，b为第二个车厢，c为第一个要对比的座位，d为第二个要对比的座位
    if(a==c) cout<<"1"; 
	else cout<<"0";
    if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
    else cout<<"0";
	if(b[2]=="A"&&d[2]=="D"||b[2]=="B"&&d[2]=="D"||b[2]=="C"&&d[2]=="D"||b[2]=="A"&&d[2]=="E"||b[2]=="B"&&d[2]=="E"||b[2]=="C"&&d[2]=="E"||b[2]=="D"&&d[2]=="A"||b[2]=="D"&&d[2]=="B"||b[2]=="D"&&d[2]=="C"||b[2]=="E"&&d[2]=="A"||b[2]=="E"&&d[2]=="B"||b[2]=="E"&&d[2]=="C") cout<<"0";
	else cout<<"1";
	if(b[2]=="A"&&d[2]=="B"||b[2]=="B"&&d[2]=="C"||b[2]=="D"&&d[2]=="E"||b[2]=="B"&&d[2]=="A"||b[2]=="C"&&d[2]=="B"||b[2]=="E"&&d[2]=="D") cout<<"1";
	else cout<<"0";
	return 0; 
}
