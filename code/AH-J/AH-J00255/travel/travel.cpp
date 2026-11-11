#include<bits/stdc++.h>
using namespace std;
bool num(char x)
{
	return x>='0'&&x<='9';
}
bool zm(char y)
{
	return y>='A'&&y<='F'&&y!='E';
}
bool ch1(char m)
{
	return m>='A'&&m<='C';
}
bool ch2(char w)
{
	return w>='D'&&w<='F'&&w!='E';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s1_num,s2_num;
	char s1_zm,s2_zm;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
		cout << "1";
	else
		cout << "0";
	for(int i = 0; i < s1.length();i++)
	{
		if(num(s1[i]))
			s1_num+=s1[i];
		if(num(s2[i]))
			s2_num+=s2[i];
		if(zm(s1[i]))
			s1_zm=s1[i];
		if(zm(s2[i]))
			s2_zm=s2[i];			
	}
	if(s1_num==s2_num&&c1==c2)
		cout << "1";
	else
		cout << "0";
	if(((ch1(s1_zm)&&ch1(s2_zm))||(ch2(s1_zm)&&ch2(s2_zm)))&&(s1_num==s2_num&&c1==c2))
		cout << "1";
	else
		cout << "0";
	if((((s1_zm==s2_zm+1&&s2_zm!='C'&&s2_zm==s1_zm-1&&s2_zm!='F')||(s2_zm==s1_zm+1&&s1_zm!='C'&&s1_zm==s2_zm-1&&s1_zm!='F'))&&(ch1(s1_zm)&&ch1(s2_zm))||(ch2(s1_zm)&&ch2(s2_zm)))&&(s1_num==s2_num&&c1==c2))
		cout << "1";
	else
		cout << "0";	
	return 0;
}
