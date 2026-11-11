#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
		string s1,s2;
		s1=b[0]+b[1];
		s2=d[0]+d[1];
		if(s1==s2){
			cout << 1;
			bool f1,f2;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				f1=1;
			}else{
				f1=0;
			}
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				f2=1;
			}else{
				f2=0;
			}
			if(f1==f2){
				cout << 1;
				bool f3;
				if(abs(b[2]-d[2])==1){
					if(b[2]=='C'&&d[2]=='D'){
						cout << 0;
						return 0;
					}
					if(b[2]=='D'&&d[2]=='C'){
						cout << 0;
						return 0;
					}
					cout << 1;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
}
