#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p1,a1,p2,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1 = int(s1[0]-'0')*10+int(s1[1]-'0');
	p2 = int(s2[0]-'0')*10+int(s2[1]-'0');
	if(s1[2] == 'A'){
		a1 = 1;
	}else if(s1[2] == 'B'){
		a1 = 2;
	}else if(s1[2] == 'C'){
		a1 = 3;
	}else if(s1[2] == 'D'){
		a1 = 5;
	}else if(s1[2] == 'F'){
		a1 = 6;
	}
	if(s2[2] == 'A'){
		a2 = 1;
	}else if(s2[2] == 'B'){
		a2 = 2;
	}else if(s2[2] == 'C'){
		a2 = 3;
	}else if(s2[2] == 'D'){
		a2 = 5;
	}else if(s2[2] == 'F'){
		a2 = 6;
	}
	if(c1 == c2){
		cout<<"1";
		if(p1 == p2){
			cout<<"1";
			if((a1 <= 3 && a2 <= 3) || (a1 >= 5 && a2 >= 5)){
				cout<<"1";
				if(abs(a1-a2) == 1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
