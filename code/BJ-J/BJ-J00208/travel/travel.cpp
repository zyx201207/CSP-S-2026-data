#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin >> a >> c >>b >> d;
	if(a==b){
		cout << "1";
		if (c[1]+c[0]==d[1]+d[0]){
		    cout << "1";
		    if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
			    cout << "1";
			    if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')){
					cout << "1";
				}
				else cout << "0";
		    }
		    else if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')){
			    cout << "11";
		    }
		    else cout << "00";
	    }
	    else cout << "000";
	}
	else cout << "0000";
	return 0;
}
