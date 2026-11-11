#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin >> a >> b >> x >> y;
	int cl=0,cr=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') cl++;
	else cr++;
	if(y[2]=='A'||y[2]=='B'||y[2]=='C') cl++;
	else cr++;
	if(a==x){
		if(b[0]==y[0]&&b[1]==y[1]){
			if(cl==2||cr==2){
				if(b[2]=='A'){
					if(y[2]=='B') cout << "1111";
					else cout << "1110";
				}else if(b[2]=='B'){
					if(y[2]=='A'||y[2]=='C') cout << "1111";
					else cout << "1110";
				}else if(b[2]=='C'){
					if(y[2]=='B') cout << "1111";
					else cout << "1110";
				}else if(b[2]=='D'){
					if(y[2]=='F') cout << "1111";
					else cout << "1110";
				}else if(b[2]=='F'){
					if(y[2]=='D') cout << "1111";
					else cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}

