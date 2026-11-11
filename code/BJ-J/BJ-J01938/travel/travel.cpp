#include <bits/stdc++.h>
using namespace std;
bool tc(char x,char y)
{
	if(((x=='A' || x=='B' || x=='C') && (y=='A' || y=='B' || y=='C')) || ((x=='D' || x=='F') && (y=='D' || y=='F'))) return true;
	else return false;
}
bool xl(char x,char y){
	if(!tc(x,y)) return false;
	if(x=='A')
	{
		if(y=='B') return true;
		else return false;
	}
	if(x=='B')
	{
		if(y=='A' || y=='C') return true;
		else return false;
	}
	if(x=='C')
	{
		if(y=='B') return true;
		else return false;
	}
	if(x=='D')
	{
		if(y=='F') return true;
		else return false;
	}
	if(x=='F')
	{
		if(y=='D') return true;
		else return false;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int n,m;
    char a,b,c;
    cin >>n>>a>>b>>c;
    int s=(a-'0')*10+b-'0';
    char x=c;
    cin >>m>>a>>b>>c;
    int t=(a-'0')*10+b-'0';
    char y=c;
    
    if(n==m)
    {
		cout <<1;
		if(s==t)
		{
			cout <<1;
			if(tc(x,y))
			{
				cout <<1;
				if(xl(x,y)) cout <<1;
				else cout <<0;
			}
			else cout <<"00";
		}
		else cout <<"000";
	}
	else cout <<"0000";
    //cout <<n<<" "<<s<<" "<<x<<" "<<m<<" "<<t<<" "<<y;
    return 0;
}
