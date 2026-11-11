#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='D'||b[2]=='F'){l+=1;}
	if(d[2]=='D'||d[2]=='F'){l+=1;}
	if(a==c&&a!="01"&&a!="16"){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			if(l%2==1){cout<<"00";}
			else{
				if(l==0){
					cout<<'1';
					if(b[2]=='A'&&d[2]=='C'||(b[2]=='C'&&d[2]=='A')){cout<<'0';}
					else{cout<<'1';}
				}
				else{cout<<"11";}
			}
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}
	return 0;
}