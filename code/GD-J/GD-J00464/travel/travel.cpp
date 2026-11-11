#include <bits/stdc++.h>
using namespace std;
bool tongce(char a,char b){
	if((a=='E'&&b=='D')||(a=='D'&&b=='E')){
		return true;
	}else if((a!='E'&&b!='D'&&a!='D'&&b!='E')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string 	cr,sr,cx,sx;
	cin >> cr >> sr>>cx>>sx;
	if(sx[2]=='F'){
		sx[2]='E';
	}
	if(sr[2]=='F'){
		sr[2]='E';
	}
	if(cr!=cx){
		cout << "0000";
	}else{
		cout << "1";
		if(sr[1]!=sx[1]||sr[0]!=sx[0]){
			cout << "000";
		}else{
			cout << "1";
			if(tongce(sr[2],sx[2])){
				cout << "1";
				if(char(sr[2]-1)==char(sx[2])||char(sr[2])==char(sx[2]-1)){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
