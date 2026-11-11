#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int js(char a,char b){
	if(a >= 'A'&& a <= 'C' && b >= 'A' && b <= 'C'&& a != c){
		return true;
	}
	else if(a == 'C'&& b =='D' && a == 'D' && b == 'F')
	{
		return true;
	}
	return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a == c)
    {
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(b[0] == d[0]and b[1] == d[1])
	{
		cout << 1 ;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(b[0] == d[0] and b[1] == d[1])
	{
		char a = b[2],b = d[2];
		if(js(a,b))
		{
			cout << 1;
		}
		else
		{
			cout << "00";
			return 0;
		}
		if(a+1 == b || (a == 'B' && b == 'F'))
		{
			cout << 1;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
}
