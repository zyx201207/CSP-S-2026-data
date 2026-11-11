#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2; int a1,a2; char b1,b2;
	cin>>c1>>a1>>b1>>c2>>a2>>b2;
	if(c1==c2){
		cout<<"1";
		if(a1==a2){
			cout<<"1";
			if(((b1=='A' || b1=='B' || b1=='C') and (b2=='A' || b2=='B' || b2=='C'))
			|| ((b1=='D' || b1=='F') and (b2=='D' || b2=='F'))){
				cout<<"1";
				if((b1=='A' and b2=='B')||(b1=='B' and b2=='C')||(b1=='D' and b2=='F')
				|| (b1=='B' and b2=='A')||(b1=='C' and b2=='B')||(b1=='F' and b2=='D')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	
	return 0;
}