#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0 , 0 , -1 , 1} , dy[4] = {1 , -1 , 0 , 0}; 
int main()
{
	freopen("travel.in" , "r" , stdin) , freopen("travel.out" , "w" , stdout);
	string a , b , c , d;
	cin>>a>>b>>c>>d;
	if(a != c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b[0] == d[0] && b[1] == d[1])
	{
		cout<<1;
		if((b[2] <= 'C' && d[2] <= 'C') || (b[2] > 'C' && d[2] > 'C'))cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	int x1 = (b[0] - '0') * 10 + b[1] - '0' , y1 = b[2] - 'A';
	int x2 = (d[0] - '0') * 10 + d[1] - '0' , y2 = d[2] - 'A';
	for(int i = 0;i <= 3;i++)
	{
		int xxx = x1 + dx[i] , yyy = y1 + dy[i];
	//	cout<<xx<<" "<<yy<<endl;
		if(xxx == x2 && yyy == y2)
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
