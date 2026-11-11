#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	string rw,xw;
	cin>>rc>>rw>>xc>>xw;
	if(rc==xc)
	cout<<1;
	else
	{

		cout<<"0000";
		return 0;
	}
	if(rw[0]==xw[0]&&rw[1]==xw[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(rw[2]=='A'||rw[2]=='B'||rw[2]=='C')
	{
	if(xw[2]=='A'||xw[2]=='B'||xw[2]=='C')
	{
		//cout<<rw[2]<<" "<<xw[2]<<endl;
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	}
	else
	{
	if(xw[2]=='E'||xw[2]=='D')
	{
		cout<<1;
	}
		else
	{
		cout<<"00";
		return 0;
	}
	}
	if(rw[2]+1==xw[2]||rw[2]-1==xw[2])
	{
		cout<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
