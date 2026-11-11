#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)
	{
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((e=='A' and f=='B') or (e=='B' and f=='C') or (e=='B' and f=='A') or (e=='C' and f=='B') or (e=='C' and f=='A') or (e=='A' and f=='C') or (e=='D' and f=='F') or (e=='F' and f=='D')){
				cout<<"1";
				if((e=='A' and f=='B') or (e=='B' and f=='C') or (e=='B' and f=='A') or (e=='C' and f=='B') or (e=='D' and f=='F') or (e=='F' and f=='D')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else{
				cout<<"00";
			}
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}
	return 0;
}
