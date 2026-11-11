#include<bits/stdc++.h>
using namespace std;
int main()

{
	
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int rs1,rs2,rsall;
	int xs1,xs2,xsall;
	int on=1,to=1,th=1,fo=0;
	string Rcar,Xcar;
	string Rsit,Xsit;
	
	cin>>Rcar;
	cin>>Rsit;
	
	cin>>Xcar;
	cin>>Xsit;
	
	if(Rcar==Xcar)
	cout<<1;
	else {
	on=0;
	cout<<on;
	}//one
	
	rs1=(int)Rsit[0];
	rs2=(int)Rsit[1];
	rsall=rs1=rs2;
	
	xs1=(int)Xsit[0];
	xs2=(int)Xsit[1];
	xsall=xs1=xs2;
	
	if(on==0)
	{
	to=on;
	cout<<0;}
	else{
	if(rsall==xsall)
	cout<<1;
	else cout<<0;
	to=on;}//two
	
	if(to==0){
	cout<<0;
	th=to;}
	else
{
	
	if(Rsit[2]==65||Rsit[2]==66||Rsit[2]==67)
	{
		if(Xsit[2]==65||Xsit[2]==66||Xsit[2]==67)
		cout<<1;
	}
	if(Rsit[2]==68||Rsit[2]==69)
	{
		if(Xsit[2]==68||Xsit[2]==69)
		cout<<1;
	}
	
}//three
	if(th==0)
	cout<<0;
	else
{
	if(Rsit[2]==65||Rsit[2]==66||Rsit[2]==Xsit[2]+1||Rsit[2]==Xsit[2]-1||Rsit[2]==Xsit[2])
	cout<<1;
	else
	{
	if(Xsit[2]==65||Xsit[2]==66||Xsit[2]==Rsit[2]+1||Xsit[2]==Rsit[2]-1||Xsit[2]==Rsit[2])
	cout<<1;
	else
	{
	
	
	if(Rsit[2]==67&&Xsit[2]==Rsit[2]-1)
	cout<<1;
	
	else{
	if(Rsit[2]==67&&Xsit[2]==Rsit[2]+1)
	cout<<fo;
	else{
	
	
	if(Rsit[2]==68&&Xsit[2]==70)
	cout<<1;
	else{
	
	
	if(Rsit[2]==70&&Xsit[2]==68)
	cout<<1;
	else{
	cout<<fo;
				}
			}
		}
	}
}
}
}
	
	return 0;

}
