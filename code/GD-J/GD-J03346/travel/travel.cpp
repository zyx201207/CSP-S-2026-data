#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
		if((c[0]-'0')*10+(c[1]-'0')==(d[0]-'0')*10+(d[1]-'0'))
		{
			cout<<1;
			char A,B;
			A=c[2],B=d[2];
			if(A>='A'&&A<='C'&&B>='A'&&B<='C')
			{
				cout<<1;
				if(A>B) swap(A,B);
				if(A=='A'&&B=='B'||A=='B'&&B=='C') cout<<1;
				else cout<<"0";
			}
			else if(A=='D'&&B=='F'||A=='F'&&B=='D') cout<<11;
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	
	return 0;
} 
