# include <bits/stdc++.h>
using namespace std;
const int N=1e5+10 ;

string a , b , c , d ;
bool f1 , f2 ;
int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin >> a >> b >> c >> d ;
	if(a!=c)
	{
		cout << "0000" ;
		return 0;
	}
	cout << "1" ;
	
	if(b[0]!=d[0] || b[1]!=d[1])
	{
		cout << "000" ;
		return 0 ;
	}
	cout << "1" ;
	
	if(b[2]>='A' && b[2]<='C')
	{
		f1=1 ;
	}
	if(d[2]>='A' && d[2]<='C')
	{
		f2=1 ;
	}
	if(f1!=f2)
	{
		cout << "00" ;
		return 0 ;
	}
	cout << "1" ;
	
	if(b[2]-d[2]==1 || b[2]-d[2]==-1)
	{
		cout << "1" ;
	}
	else if(b[2]=='F' && d[2]=='D' || b[2]=='D' && d[2]=='F')
	{
		cout << "1" ;
	}
	else
	{
		cout << "0" ;
	}
	return 0;
} 
