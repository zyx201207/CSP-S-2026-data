//准考证号：GZ-J00188 学校：遵义市新蒲新区滨湖中学  姓名：袁乙文
#include<iostream>
#include<cstdio>
#include<string> 
#include<cmath>
using namespace std;
typedef long long ll;
char ch[5]={'A','B','C','D','F'};
bool f1(string a,string c)
{
	if(((a!="16" || a!="01") && (c!="16" || c!= "01")) && a==c)
	{ 
		return 1;	
	}
	else return 0; 
}
bool f2(string b,string d)
{
	string k=b.substr(0,2),f=d.substr(0,2);
	if(k==f) 
	{
		return 1;
	}
	else return 0;
}
bool f3(string b,string d)
{
	string k=b.substr(2,2),f=d.substr(2,2);
	if(( (k=="A" || k=="B" || k=="C") && (f=="A" || f=="B" || f=="C") ) || ( (k=="D" || k=="F") && (f=="D" || f=="F")))
	
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	bool flag1=f1(a,c),flag2=f2(b,d),flag3=f3(b,d);
	
	if(flag1) cout<<1;
	else cout<<0; 
	
	if(flag2 && flag1) 
	{
		cout << 1;
	}
	else cout << 0;
	
	if(flag3 && flag2 && flag1)
	{
		cout << 1;
	}
	else cout << 0;
	
	string k=b.substr(2,2),f=d.substr(2,2);
	if(flag2 && flag1 && flag3)
	{
		if((k=="D" && f=="F") || (k=="F" && f=="D")) cout << 1;
		else if((k=="A" && f=="B") || (k=="B" && f=="A") || (k=="C" && f=="B") || (k=="B" && f=="C") )
		{
			cout << 1;
		}
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
