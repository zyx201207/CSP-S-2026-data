#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int carta,cartb,nua,nub;
	char ca,cb;
	cin>>carta>>nua>>ca>>cartb>>nub>>cb;
	if(carta==cartb) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(carta==cartb&&nua==nub) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	if(carta==cartb&&nua==nub)
	{
		if(ca<'D'&&cb<'D'||ca>'C'&&cb>'C')
		{
			cout<<1;
			if(ca=='A'&&cb=='B'||ca=='B'&&cb=='C'||cb=='A'&&ca=='B'||cb=='B'&&ca=='C'||cb=='D'&&ca=='F'||cb=='F'&&ca=='D')
			cout<<1;
			else
			cout<<0;
		}
		else
		{
			cout<<"00";
		}
		
	}
	
	
}
