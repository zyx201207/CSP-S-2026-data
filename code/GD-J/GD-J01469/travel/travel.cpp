#include<bits/stdc++.h>
using namespace std;
string ax="", ah="" , bx="" ,bh="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> ax >> ah >> bx >> bh;
	if(ax!=bx){
		cout << "0000" << endl;
		return 0;
	}else if(ah[0]!=bh[0]||ah[1]!=bh[1]){
		cout << "1000" << endl;
		return 0;
	}else if( ((ah[2]>='A'&&ah[2]<='C')&&(bh[2]=='D'||bh[2]=='F')) || ((bh[2]>='A'&&bh[2]<='C')&&(ah[2]=='D'||ah[2]=='F'))){
		cout << "1100"<< endl;
		return 0;
	}else{
		if(ah[2]>='A'&&ah[2]<='C'){
			if(ah[2]=='A'&&bh[2]=='B'){
				cout << "1111" << endl;
				return 0;
			}else if(bh[2]=='A'&&ah[2]=='B'){
				cout << "1111" << endl;
				return 0;
			}else if(ah[2]=='B'&&bh[2]=='C'){
				cout << "1111" << endl;
				return 0;
			}else if(bh[2]=='B'&&ah[2]=='C'){
				cout << "1111" << endl;
				return 0;
			}
		}else{
		    if(bh[2]=='D'&&ah[2]=='F'){
				cout << "1111" << endl;
				return 0;
			}else if(ah[2]=='D'&&bh[2]=='F'){
				cout << "1111" << endl;
				return 0;
			}
		}
	}
	cout << "1110" << endl;
	return 0;
}
