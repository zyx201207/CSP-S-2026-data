#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	if(int(a[0])==int(c[0])&&int(a[1])==int(c[1])){
		cout <<"1";
		if(int(b[0])==int(d[0])&&int(b[1])==int(d[1])){
			cout <<"1";
			if(int(char(b[2]))>=65 && int(char(b[2]))<=67){
				if(int(char(d[2]))>=65 && int(char(d[2]))<=67){
					cout <<"1"; 
					if(abs(int(char(b[2]))-int(char(d[2])))==1){
						cout <<"1";
					}else{
						cout <<"0";
					}
				}else{
					cout <<"00";
				}
			}else if(int(char(b[2]))>=68 && int(char(b[2]))<=70){
				if(int(char(d[2]))>=68 && int(char(d[2]))<=70){
					cout <<"11"; 
				}else{
					cout <<"00";
				}
			}else{
				cout <<"00";
			}
		}else{
			cout <<"000";
		}
	}else{
		cout <<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
