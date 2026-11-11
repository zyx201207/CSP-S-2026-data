#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool q=false,p=false;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char x[10],y[10];
	char t[3],u[3];
	t[0]='A';
	t[1]='B';
	t[2]='C';
	u[0]='D';
	u[1]='F';
	for(int i=0;i<3;i++){
		x[i]=b[i];
		y[i]=d[i];
	}
	for(int i=0;i<3;i++){
		if(x[2] ==u[i]){
			q=true;
		}
		if(y[2] ==u[i]){
			p=true;
		}
	}
	if(a[1]==c[1])
	{
		cout<<'1';
		if(x[0]==y[0] &&x[1]==y[1])
		{
			cout<<'1';
			if(q==p)
			{
				cout<<'1';
				if(abs(x[2]-y[2])==1 || q==false)
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
 } 
