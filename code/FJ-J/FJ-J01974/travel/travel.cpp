#include<bits/stdc++.h>
using namespace std;
bool f(char o,char p){
	int y,z;
	if(o=='A'||o=='B'||o=='C'){
		 y=1;
	}else{
		 y=0;
	}
	if(p=='A'||p=='B'||p=='C'){
		 z=1;
	}else{
		 z=0;
	}
	if(y==z){
		return true;
	}else{
		return false;
	}
}
bool e(char o,char p){
	int y,z;
	if(o=='A'||o=='B'||o=='C'){
		 y=1;
	}else{
		 y=0;
	}
	if(p=='A'||p=='B'||p=='C'){
		 z=1;
	}else{
		 z=0;
	}
	if(y==0&&z==0){
		return true;
	}else{
		if(o=='A'&&p=='B'||o=='B'&&p=='A'||o=='B'&&p=='C'||o=='C'&&p=='B'){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]){
		if(a[1]==c[1]){
			cout<<"1";
			if(b[0]==d[0]){
				if(b[1]==d[1]){
					cout<<"1";
					if(f(b[2],d[2])){
						cout<<"1";
						if(e(b[2],d[2])){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}else{
						cout<<"00";
						return 0;
					}
				}else{
					cout<<"000";
					return 0;
				}
			}else{
				cout<<"000";
				return 0;
			}
		}
		else{
			cout<<"0000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
