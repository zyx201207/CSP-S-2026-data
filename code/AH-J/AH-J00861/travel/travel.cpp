#include<bits/stdc++.h>
using namespace std;

int g(char ch) {
	switch(ch)
	{
		case 'A': return 1;
		case 'B': return 2;
		case 'C': return 3;
		case 'D': return 5;
		case 'F': return 6;
	}
	return -1;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int s1,c1,p1,s2,c2,p2;char ch;
	
	scanf(" %d",&s1);
	scanf(" %c",&ch);c1=(ch-'0')*10;
	scanf(" %c",&ch);c1+=(ch-'0');
	scanf(" %c",&ch);p1=g(ch);
	
	scanf(" %d",&s2);
	scanf(" %c",&ch);c2=(ch-'0')*10;
	scanf(" %c",&ch);c2+=(ch-'0');
	scanf(" %c",&ch);p2=g(ch);
	
	if(s1==s2) {
		cout<<"1";
		if(c1==c2) {
			cout<<"1";
			if( (p1<4 && p2<4)||(p1>4 && p2>4) ) {
				cout<<"1";
				if(p1-p2==1 || p2-p1==1) {
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
