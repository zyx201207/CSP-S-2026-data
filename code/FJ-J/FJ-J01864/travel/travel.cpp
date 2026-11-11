#include<bits/stdc++.h>
using namespace std;
long long rcx,xcx;
long long rp,xp;
char rs,xs;
long long a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rcx>>rp>>rs;
	cin>>xcx>>xp>>xs;
	if(rs=='F') rs='E';
	if(xs=='F') xs='E';
	a=rs-'A'+1;
	b=xs-'A'+1;
	if(rcx==xcx){
		cout<<'1';
		if(rp==xp){
			cout<<'1';
			if((a<=3 && b<=3) || (a>=4 && b>=4)){
				cout<<'1';
				if((abs(a-b)==1)){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
