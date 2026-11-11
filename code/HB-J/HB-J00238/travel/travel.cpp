#include <bits/stdc++.h>
using namespace std;
map<string,int> c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c["AB"]=1;
	c["AC"]=1;
	c["BA"]=1;
	c["BC"]=1;
	c["CA"]=1;
	c["CB"]=1;
	c["EF"]=1;
	c["FE"]=1;
	string x,y,x2,y2;
	cin>>x>>y>>x2>>y2;
	string cc;
	cc="";
	cc+=y[2];
	cc+=y2[2];
	if(x==x2){
		cout<<1;
		if(y[0]==y2[0] && y[1]==y2[1]){
			cout<<1;
			if(c[cc]==1){
				cout<<1;
				if(abs(y[2]-y2[2])==1){
					cout<<1;	
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
