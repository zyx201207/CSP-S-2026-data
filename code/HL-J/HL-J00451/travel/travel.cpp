#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rch, R, Xch, X;
	cin>>Rch>>R>>Xch>>X;
	char R_seat1=R[0],R_seat2=R[1],R_seat3=R[2], X_seat1=X[0],X_seat2=X[1],X_seat3=X[2];
	if (Rch==Xch){
		cout<<"1";
		if ((R_seat1==X_seat1) && (R_seat2==X_seat2)){
			cout<<"1";
			if (((R_seat3=='A') || (R_seat3=='B') || (R_seat3=='C')) && (('A'==X_seat3) || (X_seat3=='B') || (X_seat3=='C'))){
				cout<<"1";
				if ((('A'==R_seat3) && (X_seat3=='B')) || (('A'==X_seat3) && (R_seat3=='B'))){
					cout<<"1";
				}
				else if ((('C'==R_seat3) && (X_seat3=='B')) || (('C'==X_seat3) && (R_seat3=='B'))){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if ((('D'==R_seat3) && (X_seat3=='F')) || (('D'==X_seat3) && (R_seat3=='F'))){
				cout<<"11";
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
