#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,t1,s2,t2;
	cin >> s1 >> t1 >> s2 >> t2;
	if(s1 != s2){
		cout << "0000";
	}else if(t1[0]!=t2[0]||t1[1]!=t2[1]){
		cout << "1000";
	}else{
		bool a=0,b=0;
		if(t1[2]>='A'&&t1[2]<='C') a=1;
		if(t2[2]>='A'&&t2[2]<='C') b=1;
		if(a==b){
			char x = t1[2],y=t2[2];
			if(x=='C'&&y=='D'){
				cout << "1110";
			}else if(x == 'D'&&y=='C'){
				cout << "1110";
			}else if(x == y-1||x==y+1){
				cout << "1111";
			}else{
				cout << "1110";
			}
		}else{
			cout << "1100";
		}
	}

	return 0;
}
