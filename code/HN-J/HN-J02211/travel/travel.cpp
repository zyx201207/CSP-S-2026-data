#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if((b[2]=='D'&&d[2]=='F')||b[2]=='D'&&d[2]=='F'){
				cout<<1111;
				return 0;
			}
			else if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
				int s=int(b[2])-int(d[2]);
				s=abs(s);
				if(s==1)cout<<1111;
				else cout<<1110;
			}
			else cout<<1100;
		}
		else {
			cout<<1000;
		}
	}
	else {
	    cout<<"0000";
	}
	return 0;
}
