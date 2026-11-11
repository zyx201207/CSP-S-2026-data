#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string r,rr,x,xx;
	cin >> r >> rr >> x >> xx;
	string s="";
	if(r==x){
		if(rr[0]==xx[0]&&rr[1]==xx[1]){
			if(((rr[2]=='A'||rr[2]=='B'||rr[2]=='C')&&(xx[2]=='A'||xx[2]=='B'||xx[2]=='C'))){
				if((rr[2]=='A'&&xx[2]=='B')||(rr[2]=='B'&&xx[2]=='C')||(rr[2]=='B'&&xx[2]=='A')||(rr[2]=='C'&&xx[2]=='B')){
					cout << "1111";
				}
				else{
					cout << "1110";
				}
			}
			else if((rr[2]=='D'||rr[2]=='F')&&(xx[2]=='D'||xx[2]=='F')){
				cout << "1111";
			}
			else{
				cout << "1100";
			}
		}
		else{
			cout << "1000";
		}
	}
	else{
		cout << "0000";
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
} 
