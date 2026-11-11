#include<bits/stdc++.h>
using namespace std;
string s;
int xc,xp,xz,yc,yp,yz;
string an;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	xc=(s[0]-'0')*10+s[1]-'0';
	xp=(s[3]-'0')*10+s[4]-'0';
	xz=(s[5]-'A')+1;
	yc=(s[7]-'0')*10+s[8]-'0';
	yp=(s[10]-'0')*10+s[11]-'0';
	yz=s[12]-'A'+1;
	if(xc!=yc){
		an="0000";
		cout<<an;
		return 0;
	}
	else{
		if(xp!=yp){
			an="1000";
			cout<<an;
			return 0;
		}
		else{
			if((xz<=3&&yz<=3)||(xz>=4&&yz>=4)){
				if(xz-1==yz||xz+1==yz){
					an="1111";
					cout<<an;
					return 0;
				}
				else{
					an="1110";
					cout<<an;
					return 0;
				}
			}
			else{
				an="1100";
				cout<<an;
				return 0;
			}
		}
	}
	return 0;
}
