#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<"1";
			if(s[2]<='C'&&ss[2]<='C'){
				cout<<"1";
				if(s[2]=='A'&&ss[2]=='B'){
					cout<<"1";
				}else if(s[2]=='B'&&ss[2]=='A'){
					cout<<"1";
				}else if(s[2]=='B'&&ss[2]=='C'){
					cout<<"1";
				}else if(s[2]=='C'&&ss[2]=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(s[2]>='D'&&ss[2]>='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
