#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int a2,b2,c2,d2,e2;
	a2='A';
	b2='B';
	c2='C';
	d2='D';
	e2='E';
	if(a==d)
	cout<<"1000"<<endl;
	else{
		cout<<"0000"<<endl;
		if(a==d and b==e)
		cout<<"1100"<<endl;
		else{
			cout<<"1000"<<endl;
			if(a==d and b==e and c+f==a2+b2 and c+f==a2+c2 and c+f==b2+c2 and c+f==d2+e2)
			cout<<"1110"<<endl;
			else{
				cout<<"1100"<<endl;
				if(a==d and b==e and c+f==a2+b2 and c+f==b2+c2 and c+f==d2+e2)
				cout<<"1111"<<endl;
				else{
					cout<<"1110"<<endl;
					}
				}
			}
		}
	return 0;
}
