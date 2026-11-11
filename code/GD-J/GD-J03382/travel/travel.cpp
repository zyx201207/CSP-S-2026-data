#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string so,st;
	int co,ct;
	cin>>co>>so>>ct>>st;
	char ax=so[0],bx=so[1],cx=so[2];
	char ay=st[0],by=st[1],cy=st[2];
	if(co==ct){
		cout<<1;
		if(ax==ay&&bx==by){
			cout<<1;
			if(cx>='A'&&cx<='C'&&cy>='A'&&cy<='C'){
				cout<<1;
				if(cx=='A'&&cy=='B'){
					cout<<1;
				}
				else if(cx=='B'&&cy=='A'){
					cout<<1;
				}
				else if(cx=='B'&&cy=='C'){
					cout<<1;
				}
				else if(cx=='C'&&cy=='B'){
					cout<<1;
				}
				else cout<<0;
			}
			else if(cx=='D'&&cy=='F'){
				cout<<"11";
			}
			else if(cx=='F'&&cy=='D'){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
