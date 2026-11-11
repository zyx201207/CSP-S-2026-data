#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r2,r1,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	bool ok=1;
	if(r1!=x1){
		cout<<"0";
		ok=0;
	}
	else{
		cout<<"1";
	}//ok
	string r22=r2,x22=x2;
	r22.erase(2);
	x22.erase(2);
	if(r22==x22&&ok){//?
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(r22==x22&&ok){
		if((r2[2]=='F'||r2[2]=='D')&&(x2[2]=='F'||x2[2]=='D')){
			cout<<"11";
		}
		if((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C')){
			cout<<"1";
			if((r2[2]=='A'&&x2[2]=='B')||(r2[2]=='B'&&(x2[2]=='C'||x2[2]=='A'))||(r2[2]=='C'&&x2[2]=='B')||/**/(x2[2]=='A'&&r2[2]=='B')||(x2[2]=='B'&&(r2[2]=='C'||r2[2]=='A'))||(x2[2]=='C'&&r2[2]=='B')){cout<<"1";}else{cout<<'0';}
		}
	}
	else{
		cout<<"00";
	}
	return 0;
}
