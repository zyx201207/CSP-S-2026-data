#include<bits/stdc++.h> 
using namespace std;
int xcoach,rcoach;
string xseat,rseat;
const int C=('A'-'0');
int get_pai(string seat)
{
	return (seat[0]-C)*10+seat[1]-C;
}
char get_seat(string seat)
{
	return seat[2];
}
int main()
{
	bool yice=1;
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>rcoach>>rseat>>xcoach>>xseat;
	//≈–∂œ≥µœ·
	if(rcoach==xcoach) cout<<1;
	else 
	{
	    cout<<0;
		yice=0;	
	}
	//≈–∂œ“ª≈≈
	if(get_pai(rseat)==get_pai(xseat)&&yice==1) cout<<1; 
	else 
	{
	    cout<<0;	
	    yice=0;
	}
	//≈–∂œ“ª≤‡
	const char R=get_seat(rseat);
	const char X=get_seat(xseat);
	if(yice==1)
	{			
		if(((R=='A') || (R=='B') || (R=='C'))  &&  ((X!='D') && (X!='E')) )
		{		
		    cout<<1;
		}
		else if(((R=='D') || (R=='E'))  &&  (((X=='D') || (X=='E')))) 
		{
		    cout<<1;
		}	  
		else 
		{
			cout<<0;
			yice=0;
		}
	}
	else
	{
		cout<<0;
		yice=0;
	}
	//≈–∂œœ‡¡⁄
	if(yice==0) cout<<0;
	else
	{
		if((R=='D')||(X=='D')) cout<<1;
		else if(((R=='A')&&(X=='B'))||((R=='B')&&(X=='A'))) cout<<1;
		else if(((R=='B')&&(X=='C'))||((R=='C')&&(X=='B'))) cout<<1;
		else cout<<0;	
	} 
	return 0;
}
