//GZ-J00001 贵阳市实验三中 夏上云
#include <iostream>
using namespace std;

bool f(string a,string b){
	string s1 = "";
	string s2 = "";
	for(int i = 0;i <= a.size()-2;i++)
	{
		s1 += a[i];
		s2 += b[i];
	}
	return(s1 == s2);
}
bool s(string a,string b){
	char s1 = a[2];
	char s2 = b[2];
	if(s1 == 'D' && s2 == 'F' || s1 == 'F' && s2 == 'D') return 1;
	if(s1 == 'A' && s2 == 'B' || s1 == 'A' && s2 == 'C' || s1 == 'B' && s2 == 'C' || s1 == 'B' && s2 == 'A' || s1 == 'C' && s2 == 'A' || s1 == 'C' && s2 == 'B') return 1;
	return 0;
}
bool v(string a,string b)
{
	char s1 = a[2];
	char s2 = b[2];
	if(s1 == 'D' && s2 == 'F' || s1 == 'F' && s2 == 'D') return 1;
	if(s1 == 'A' && s2 == 'B' || s1 == 'B' && s2 == 'C' || s1 == 'B' && s2 == 'A' || s1 == 'C' && s2 == 'B') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 != s2)
	{
		cout << "0000";
	}
	else if(f(c1,c2) == 0)
	{
		cout << "1000";
	}
	else if(s(c1,c2) == 0)
	{
		cout << "1100";
	}
	else if(v(c1,c2) == 0)
	{
		cout << "1110";
	}
	else
	{
		cout << "1111";
	}
	return 0;
}
