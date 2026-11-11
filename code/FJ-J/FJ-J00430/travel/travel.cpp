#include<bits/stdc++.h>
using namespace std;
string nr,nx,mr,mx;
int hr,hx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>nr>>mr>>nx>>mx;
	hr=(nr[0]-'0')*10+(nr[1]-'0'),hx=(nx[0]-'0')*10+(nx[1]-'0');
	if(hr==hx)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	hr=(mr[0]-'0')*10+(mr[1]-'0'),hx=(mx[0]-'0')*10+(mx[1]-'0');
	if(hr==hx){
		cout<<'1';
		hr=(mr[2]-'A'+1),hx=(mx[2]-'A'+1);
		if(hr<=3&&hx<=3)cout<<'1';
		else if(hr>3 && hx>3){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
		if(hr-hx==1 || hx-hr==1)cout<<'1';
		else cout<<'0';
	}else{
		cout<<"000";
	}
	return 0;
}