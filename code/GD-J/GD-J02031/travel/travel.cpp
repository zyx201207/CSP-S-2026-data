#include<bits/stdc++.h>
using namespace std;
int co,cs;
string so,ss;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>co>>so>>cs>>ss;
	bool c=false;
	if(co==cs){
		c=true;
		cout<<1;
	}
	else if(co!=cs){
		cout<<0;
	}
	bool f=false;
	if(so[0]==ss[0] and so[1]==ss[1] and c==true){
		f=true;
		cout<<1;
	}else{
		cout<<0;
	}
	if((so[2]>=65 and so[2]<=67 and ss[2]>=65 and ss[2]<=67 and f==true and c==true)||(so[2]>=68 and so[2]<=70 and ss[2]>=68 and ss[2]<=70 and so[2]!=69 and ss[2]!=69 and f==true and c==true)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(abs(so[2]-ss[2])==1 and so[2]!=67 and so[2]!=68 and ss[2]!=67 and ss[2]!=68 and f==true and c==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
