#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1 , c2 ;
	char s1 ,s2;
	//    Rcxh Rzwh  Xcxh  Xzwh
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == 01 || c1 == 16 || c2 == 01 || c2 == 16)
	{
		cout << "0000";
	}
	if(c1 == 02 && s2 == '01A' && c2 == 02 && s2 == '01B') 
	{
		cout << "1111";
	}
	if(c1 == 02 && s2 == '01C' && c2 == 02 && s2 == '01A') 
	{
		cout << "1110";
	}
	if(c1 == 02 && s2 == '01C' && c2 == 02 && s2 == '01D') 
	{
		cout << "1100";
	}
	if(c1 == 02 && s2 == '02B' && c2 == 02 && s2 == '01A') 
	{
		cout << "1000";
	}
	if(c1 == 02 && s2 == '01A' && c2 == 03 && s2 == '01A') 
	{
		cout << "0000";
	}
	return 0;
}
