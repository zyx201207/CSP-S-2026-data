#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
int x1,x2,x3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c;
	cin>>c1>>s1>>c;
	x1=int(c);
	cin>>c2>>s2>>c;
	x2=int(c);
	x3=min(x1,x2);
	x1=max(x1,x2); 
	x2=x3;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(x1<=67&&x2<=67){
				cout<<"1";
				if(x2+1==x1)cout<<"1";
				else cout<<"0";
			}
			else if(x1>=68&&x2>=68) cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
