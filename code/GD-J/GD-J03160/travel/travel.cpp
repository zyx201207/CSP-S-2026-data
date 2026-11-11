#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0]==s[7]&&s[1]==s[8])
	{
		cout<<1;
		if(s[3]==s[10]&&s[4]==s[11])
		{
			cout<<1;
			if((s[5]>'C'&&s[12]<='C')||(s[5]<='C'&&s[12]>'C'))
			{
				cout<<"00";
			}
			else{
				int x=s[5],y=s[12];
				if(abs(x-y)==1)cout<<11;
				else cout<<10;
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} //100
