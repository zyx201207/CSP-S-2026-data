#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	int rcx,rp,rw,xcx,xp,xw;
	rcx=(a[0]-'0')*10+(a[1]-'0');
	rp=(b[0]-'0')*10+(b[1]-'0');
	rw=b[2]-'A';
	xcx=(c[0]-'0')*10+(c[1]-'0');
	xp=(d[0]-'0')*10+(d[1]-'0');
	xw=d[2]-'A';
	if(rcx==xcx){
		cout<<1;
		if(rp==xp){
			cout<<"1";
			if((rw<=2&&xw<=2)||(rw>=3&&xw>=3)){
				cout<<"1";
				if(abs(rw-xw)==1&&!(xw==2&&rw==3)&&!(xw==3&&rw==2))
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
