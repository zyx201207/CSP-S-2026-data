#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,p1,c2,p2;
	char w1,w2;
	cin >> c1 >> p1 >> w1 >> c2 >> p2 >> w2;
	if(c1==c2){
		cout << 1;
		if(p1==p2){
			cout << 1;
			if((w1>='A'&&w1<='C'&&w2>='A'&&w2<='C')||(w1>='D'&&w1<='F'&&w2>='D'&&w2<='F')){
				cout << 1;
				if(abs(w1-w2)==1)cout << 1;
				else cout << 0;
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	cout << '\n';
	return 0;
}
