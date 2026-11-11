#include<bits/stdc++.h>
using namespace std;
int ax,bx,ay,by;
char cx,cy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>bx>>cx>>ay>>by>>cy;
	if(ax==ay){
		cout<<"1";
		if(bx==by){
			cout<<"1";
			if((cx=='D'&&cy=='F')||(cy=='D'&&cx=='F')||(cx=='A'&&cy=='B')||(cx=='B'&&cy=='C')||(cx=='B'&&cy=='A')||(cx=='C'&&cy=='B')){
				cout<<"11";
			}else if((cx=='A'&&cy=='C')||(cx=='C'&&cy=='A')){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
