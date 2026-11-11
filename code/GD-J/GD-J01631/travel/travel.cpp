#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string a,b,c,d;
int main(int argc, char** argv) {freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a >> b >> c >> d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout << 1;
	}else
	    cout << 0;
	if(b[0]==d[0]&&b[1]==d[1]&&a[0]==c[0]&&a[1]==c[1]){
		cout << 1;
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout << 1;
				if(b[2]=='A'&&d[2]=='C'){
					cout << 0;
				} else
				    if(b[2]=='C'&&d[2]=='A'){
					    cout << 0;
				    } else cout << 1;
		    }else cout << 0 << 0;
		}else{
			if(b[2]=='F'||b[2]=='D'){
			    if(d[2]=='F'||d[2]=='D'){
				    cout << 1 << 1;
				}else cout << 0 << 0;
		    }else 
			   cout << 0 << 0;
		}
	}else
	    cout << 0 << 0 << 0;
	return 0;
}
