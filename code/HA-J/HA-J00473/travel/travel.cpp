#include<bits/stdc++.h>
using namespace std;
string a , b, c ,d;
bool check[6][6];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(b[2]=='F')b[2]='E';
	if(d[2]=='F')d[2]='E';
	memset(check,0,sizeof(check));
	for(int i = 1; i <= 3 ; i++)
	for(int j = 1; j <= 3 ; j++)
	check[i][j]=1;
	for(int i = 4; i <= 5; i++)
	for(int j = 4; j <= 5; j++)
	check[i][j]=1;
	if(a==c)
	{
		cout << "1";
		if(b.substr(0,2)==d.substr(0,2))
		{
		cout << "1";
		if(check[b[2]-'A'+1][d[2]-'A'+1])
		{
		cout << "1";
		if(abs(b[2]-d[2])==1)
		cout << "1";
		else cout << "0";
		}
		else cout << "00";
	    }
	    else cout << "000";
	}
	else cout <<"0000";
	return 0;
}
