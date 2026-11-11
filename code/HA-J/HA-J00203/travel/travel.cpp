#include<bits/stdc++.h>
#define ll long long
using namespace std;
string ax,bx,ay,by;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>bx>>ay>>by;
	if(ax==ay){
		cout<<"1";
		if(bx[1]==by[1]&&bx[0]==by[0]){
			cout<<"1";
			if(bx[2]-65==3 || bx[2]-65==5 || by[2]-65==3 || by[2]-65==5){
				if((bx[2]-65)-(by[2]-65)==2 || (bx[2]-65)-(by[2]-65)==-2){cout<<"11";return 0;}
				else{cout<<"00";return 0;}
			}else{
				if((bx[2]-65)+(by[2]-65)<4){
					cout<<"1";
					if((bx[2]-65)-(by[2]-65)==1 || (bx[2]-65)-(by[2]-65)==-1){cout<<"1";return 0;}
					else{cout<<"0";return 0;}
				}
			}
		}else{cout<<"000";return 0;}
	}else cout<<"0000";
	return 0; 
}
// fixed setprecision(number) 
// greater<int>()
