#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char k1,k2;
	cin>>c1>>s1>>k1>>c2>>s2>>k2;
	if(c1==c2){
		cout << 1;
		if(s1==s2){
			cout << 1;
			if((k1=='A' || k1=='B' || k1=='C') && (k2=='A' || k2=='B' || k2=='C')){
				cout << 1;
				if(k1>k2) swap(k1,k2);
				if(k1+1==k2) cout << 1;
				else cout << "0";
			}else if((k1=='D' || k1=='F') && (k2=='D' || k2=='F')){
				cout << 1;
				if(k1>k2) swap(k1,k2);
				if(k1+2==k2) cout << 1;
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	return 0;
}
