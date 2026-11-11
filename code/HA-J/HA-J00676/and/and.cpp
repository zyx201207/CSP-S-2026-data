#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.cpp","r",stdin);
	freopen("travel.cpp","w",stdout);
	string Q,x,W,y;
	cin >> Q >> x >> W >> y;
	if(Q == W){
		cout << 1;
	}else{
		cout << 0;
	}
	string h[18]={"01F","02F","03F","04F","05F","06F","07F","08F","09F","10F","11F","12F","13F","14F","15F","16F","17F","18F"};
	string j[18]={"01D","02D","03D","04D","05D","06D","07D","08D","09D","10D","11D","12D","13D","14D","15D","16D","17D","18D"};
	string k[18]={"01C","02C","03C","04C","05C","06C","07C","08C","09C","10C","11C","12C","13C","14C","15C","16C","17C","18C"};
	string l[18]={"01B","02B","03B","04B","05B","06B","07B","08B","09B","10B","11B","12B","13B","14B","15B","16B","17B","18B"};
	string p[18]={"01A","02A","03A","04A","05A","06A","07A","08A","09A","10A","11A","12A","13A","14A","15A","16A","17A","18A"};
	bool a[18];
	bool b[18];
	bool c[18];
	bool d[18];
	bool e[18];
	for(int i=0;i<=17;i++){
		if(x==h[i]){
			a[i]=1;
		}else if(x==j[i]){
			b[i]=1;
		}else if(x==k[i]){
			c[i]=1;
		}else if(x==l[i]){
			d[i]=1;
		}else if(x==p[i]){
			e[i]=1;
		}
		if(y==h[i]){
			a[i]=1;
		}else if(y==j[i]){
			b[i]=1;
		}else if(y==k[i]){
			c[i]=1;
		}else if(y==l[i]){
			d[i]=1;
		}else if(x==p[i]){
			e[i]=1;
		}
	}
	for(int i=0;i<=17;i++){
		if(a[i]!= 0){
			if(b[i] != 0 || c[i] != 0 || d[i] != 0 || e[i] != 0){
				cout << 1;
				if(b[i] != 0){
					cout << 1;
					cout << 1;
					return 0;
				}else{
					cout << 0;
					cout << 0;
					return 0;
				}
			}else{
				cout << 0;
				cout << 0;
				cout << 0;
				break;
			}
		}
		if(b[i]!= 0){
			if(a[i] != 0 || c[i] != 0 || d[i] != 0 || e[i] != 0){
				cout << 1;
				if(a[i] != 0){
					cout << 1;
					cout << 1;
					return 0;
				}else{
					cout << 0;
				}
				if(c[i] != 0){
					cout << 1;
					return 0;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << 0;
				cout << 0;
				cout << 0;
				break;
			}
		}
		if(c[i]!= 0){
			if(b[i] != 0 || a[i] != 0 || d[i] != 0 || e[i] != 0){
				cout << 1;
				if(d[i] != 0){
					cout << 1;
					cout << 1;
					return 0;
				}else{
					if(e[i] != 0){
						cout << 1;
					}else{
						cout << 0;
					}
				}
				if(b[i] != 0){
					cout << 1;
					return 0;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << 0;
				cout << 0;
				cout << 0;
				break;
			}
		}
		if(d[i]!= 0){
			if(b[i] != 0 || c[i] != 0 || d[i] != 0 || e[i] != 0){
				cout << 1;
				if(c[i] != 0){
					cout << 1;
					cout << 1;
					return 0;
				}else{
					if(e[i] != 0){
						cout << 1;
						cout << 1;
						return 0;
					}else{
						cout << 0;
						cout << 0;
						return 0;
					}
				}
			}else{
				cout << 0;
				cout << 0;
				cout << 0;
				break;
			}
		}
		if(e[i]!= 0){
			if(b[i] != 0 || c[i] != 0 || d[i] != 0 || a[i] != 0){
				cout << 1;
				if(c[i] != 0){
					cout << 1;
				}else{
					if(d[i] != 0){
						cout << 1;
						cout << 1;
						return 0;
					}else{
						cout << 0;
						cout << 0;
						return 0;
					}
				}
			}else{
				cout << 0;
				cout << 0;
				cout << 0;
				break;
			}
		}
	}
	return 0;
}








