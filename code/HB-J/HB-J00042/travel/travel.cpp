#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int s11 = (s1[0]-'0')*10+s1[1]-'0';
	int s22 = (s2[0]-'0')*10+s2[1]-'0';
	bool isc = false,isp = false;
	int e1 = s1[2],e2 = s2[2];
	//1st
	if(c1 == c2)
	{
		isc = true;
		cout << "1";
	}
	else
		cout << "0";
	
	//2nd
	if(isc == true && s11==s22)
	{
		cout << "1";
		isp = true;
	}
	else
		cout << "0";
	//3rd
	if(isp == true)
	{
		if((e1<='C'&&e2<='C') || (e1>'C'&&e2>'C'))
		{
			cout << "1";
		}
		else
			cout << "0";
	}
	else
		cout << "0";
	
	//4nd
	if(s11 == s22 && isc == true)
	{
		if((s1[2]==s2[2] || s1[2]==s2[2]+1 || s1[2]==s2[2]-1))
		{
			if((s1[2] == 'C' && s2[2] == 'D')||(s1[2] == 'D' && s2[2] == 'C'))
				cout << "0";
			else
				cout << "1";
		}
		else
			cout << "0";
	}
	else if(( s11 == s22-1 || s11 == s22+1)&&isc == true)
	{
		if(s1[2]==s2[2])
			cout << "1";
		else 
			cout << "0";
	}
	else
		cout << "0";
	return 0;
	
}
