#include<bits/stdc++.h>
using namespace std;
int a,b,i;
string a2,b2;
bool s = false,r = false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2;
	cin>>b>>b2;
	if(a == b){
		cout<<"1";
		s = true;
	}else{
		if(s == false){
			cout<<"0000";
		}
		return 0;	
	}
	if(s == true && a2[0] == b2[0] && a2[1]  == b2[1]){
			cout<<"1";
			r = true;
	}else{
		if(r == false){
			cout<<"000";
		}
		return 0;
	}
	if(r == true && a2[2] == 'F'){
		if(b2[2] == 'D'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(r == true && a2[2] == 'D'){
		if(b2[2] == 'F'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(r == true && a2[2] == 'A'){
		if(b2[2] == 'B' or b2[2] == 'C'){
			cout<<"1";
			if(b2[2] == 'B'){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}else if(r == true && a2[2] == 'B'){
		if(b2[2] == 'A' or b2[2] == 'C'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
		}
	}else if(r == true && a2[2] == 'C'){
		if(b2[2] == 'A' or b2[2] == 'B'){
			cout<<"1";
			if(b2[2] == 'B'){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
