#include<bits/stdc++.h>
using namespace std;
struct node
{
	string a,b ;
}x,y ;
int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin>>x.a>>x.b>>y.a>>y.b ;	
	if(x.a!=y.a) 
	{
		cout<<"0000" ;
		return 0 ;
	}
	else 
	{
		cout<<'1' ;
		int xx=(x.b[0]-'0')*10+x.b[1]-'0',yy=(y.b[0]-'0')*10+y.b[1]-'0' ;
		if(xx==yy) 
		{
			cout<<'1' ;
			if(x.b[2]>='D'&&y.b[2]>='D') 
				cout<<"11" ;
			else if(x.b[2]<'D'&&y.b[2]<'D')
			{
				cout<<'1' ;
				if(abs(int(x.b[2])-int(y.b[2]))==1) cout<<'1' ;
				else cout<<'0' ;
			}
			else cout<<"00" ;
		}
		else cout<<"000" ;
	}
}
