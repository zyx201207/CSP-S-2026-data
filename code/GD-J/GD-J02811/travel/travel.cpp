#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,x,y;
	cin >> n >> m >> x >> y;
	int n1=0,m1=0,x1=0,y1=0;
	char m2=' ',y2=' ';
	n1=(n[0]-'0')*10+(n[1]-'0');
	m1=(m[0]-'0')*10+(m[1]-'0');
	x1=(x[0]-'0')*10+(x[1]-'0');
	y1=(y[0]-'0')*10+(y[1]-'0');
	m2=m[2];
	y2=y[2];
	if(n1==x1){
		cout << 1;
		if(m1==y1){
			cout << 1;
			if(m2>='A' and m2<='C' and y2>='A' and y2<='C'){
				cout << 1;
				char m3=m2+1,m4=m2-1;
				if(m3==y2 || m4==y2){
					cout << 1;
					return 0;
				}else{
					cout << 0;
					return 0;
				}
			}else if(m2>='D' and m2<='F' and y2>='D' and y2<='F'){
				cout << 1 << 1;
				return 0;
			}else{
				cout << 0 << 0;
				return 0;
			}
		}else{
			cout << 0 << 0 << 0;
			return 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	return 0;
}
