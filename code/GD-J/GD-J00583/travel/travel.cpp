#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,n,b,m;
	cin >> a >> n >> b >> m;
	int c = 0;
	if(a == b){
		cout << 1;
		for(int i = 1;i <= 2;i++){
			if(a[i] == b[i]) c++;
		}
		if(c == 2){
			cout << 1;
			if(((a[3]=='A'||a[3]=='B'||a[3]=='C')&&(b[3]=='A'||b[3]=='B'||b[3]=='C'))||((a[3]=='D'||a[3]=='E')&&(b[3]=='D'||b[3]=='E'))){
				cout << 1;
				if(((a[3]=='A'||a[3]=='B')&&(b[3]=='B'||b[3]=='A'))||((a[3]=='B'||a[3]=='C')&&(b[3]=='C'||b[3]=='B'))||((a[3]=='E'||a[3]=='F')&&(b[3]=='F'||b[3]=='E'))){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
