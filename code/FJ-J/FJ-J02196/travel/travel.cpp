#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1,a2,b2;
	char c1,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1!=a2) cout<<"0000";
	else{
		cout<<'1';
		if(b1!=b2) cout<<"000";
		else{
			cout<<'1';
			if((c1=='A'||c1=='B'||c1=='C')&&(c1=='A'||c1=='B'||c1=='C'))
			{
				cout<<'1';
				if(c1+1==c2||c2+1==c1) cout<<'1';
				else cout<<'0';
			}
			else if((c1=='D'||c1=='F')&&(c1=='D'||c1=='F'))
			{
				cout<<'1';
				if(c1+1==c2||c2+1==c1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
	}
	return 0;
}
