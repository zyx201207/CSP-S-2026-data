#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
char a1[5]={'A','B','C'};
char a2[5]={'D','F'};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1==c2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	
	if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
		cout << 1;
	}
	else{
		cout << 0;
	}
	int f=0;
	bool p=0;
	if((s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
		if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
			for(int i=0;i<=2;i++){
				if(a1[i]==s1[2]){
					f++;
				}
				if(a1[i]==s2[2]){
					f++;
				}
			}
			if(f==2){
				cout << 1;
				p=1;
			}
			else{
				cout << 0;
			}
		}
		else if(s1[2]=='D' || s1[2]=='E'){
			for(int i=0;i<=1;i++){
				if(a2[i]==s1[2]){
					f++;
				}
				if(a2[i]==s2[2]){
					f++;
				}
			}
			if(f==2){
				cout << 1;
				p=1;
			}
			else{
				cout << 0;
			}
		}
	}
	else{
		cout << 0;
	}
	if(p==0){
		cout << 0;
	}
	else{
		if(abs(s1[2]-s2[2])==1) {
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	return 0;
}
