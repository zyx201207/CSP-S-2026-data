#include<bits/stdc++.h>
using namespace std;
#define int long long
string c,s,cc,ss;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c==cc){
		if(s[0]==ss[0] and s[1]==ss[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	int a=s[2]-'A';
	int b=ss[2]-'A';
	if(a==5){
		a=4;
	}
	if(b==5){
		b=4;
	}
	if(c==cc){
		if(s[0]==ss[0] and s[1]==ss[1]){
			if((a<=2 and b<=2) or ((s[2]=='D' and ss[2]=='F') or (s[2]=='F' and ss[2]=='D'))){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(c==cc){
		if(s[0]==ss[0] and s[1]==ss[1]){
			if((a<=2 and b<=2) or ((s[2]=='D' and ss[2]=='F') or (s[2]=='F' and ss[2]=='D'))){
				if(abs(b-a)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
