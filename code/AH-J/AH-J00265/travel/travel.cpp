#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,b;
	char c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		a=s1[0]*10+s1[1];
		b=s2[0]*10+s2[1];
		if(a==b)
		{
			cout<<"1";
			c=s1[2];
			d=s2[2];
			if(c==65&&d==66 || c==65&&d==67 || c==66&&d==65 || c==66&&d==67 || c==67&&d==65 || c==67&&d==66 || c==68&&d==69 || c==69&&d==68)
			{
				cout<<"1";
				if(c+1==d||c-1==d)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
