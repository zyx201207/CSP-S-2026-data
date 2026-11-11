#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string a,b,x,y;
	cin >> a >> b >> x >> y;
	char p=b[2],q=y[2];
	b=b[0]+b[1],y=y[0]+y[1];
	if(p-'0'>q-'0') swap(p,q);
	if(a!=x){
		cout << "0000";
		return 0;
	}else cout << 1;
	if(b!=y){
		cout << "000";
		return 0;
	}else cout << 1;
	if(p=='D'&&q=='F'){
		cout << 11;
		return 0;
	}
	if(p=='D'||p=='F'||q=='D'||q=='F'){
		cout << "00";
		return 0;
	}
	if(p=='A'){
		if(q=='B'){
			cout << 11;
			return 0;
		}
		if(q=='C'){
			cout << 10;
			return 0;
		}
	}
	cout << 11;
	return 0;
} 
