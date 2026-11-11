#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int cnt=0;
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1==c3)
	{
		cout << 1;
		cnt++;
	}
	else 
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(c2[0]+c2[1]==c4[0]+c4[1])
	{
		cout << 1;
		cnt++;
	}
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(c2[2]+c4[2]=='A'+'B' || c2[2]+c4[2]=='C'+'B')
	{
		cout << 1 << 1;
		cnt+=2;
	}
	else if(c2[2]+c4[2]=='A'+'C')
	{
		cout << 1 << 0;
		return 0;
	}
	else if(c2[2]=='D' || c2[2]=='F' && c4[2]=='D' || c4[2]=='F')
	{
		cout << 1 << 1;
		cnt+=2;
	}
	else if(cnt==4) return 0;
	else cout << 0 << 0;
	return 0;
}
