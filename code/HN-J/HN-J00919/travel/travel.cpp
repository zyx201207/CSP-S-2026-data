#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else {
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2)){
			cout<<1;
			if(((char)b[2]<='C'&&(char)d[2]<='C')||((char)b[2]>'C'&&(char)d[2]>'C'))
			{
				cout<<1;
				if(b[2]-d[2]==1||d[2]-b[2]==1)
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}
