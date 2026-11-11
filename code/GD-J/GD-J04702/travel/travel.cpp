#include <bits/stdc++.h>
using namespace std;
string C1,C2[10005],S1,S2[10005];
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> C1 >> S1;
	for(int i=0;i<3;i++){
		cin >> C2[i];
	}
	for(int i=0;i<3;i++){
		cin >> S2[i];
	}
	if(C1==S1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	for(int i=0;i<2;i++){
		if(C2[0]==S2[0]){
			if(C2[1]==S2[1]){
				cout << 1;
			}
		}
		else if(C2[0]!=S2[0]){
			if(C2[1]!=S2[1]){
				cout << 0;
			}
		}
	}
	if(C2[2]=='A''||'B'||'C'&&S2[2]='A''||'B'||'C'){
		cout << 1;
	}
	else if(c2[2]=='D''||'F'&&S2[2]='D''||'F'){
		cout <<1;
	}
	else{
		cout<<0;
	}
	if(C2[1]==S2[1] && C2[2]-S2[2]==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
