#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << '1';
		char s1l=s1[2],s2l=s2[2];
		int pan=0;
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i]){
				cout << "000";
				pan=1;
				break;
			}
		}
		if(pan==0){
			cout << '1';
			if((s1l<='C' and s2l<='C') or (s1l>='D' and s2l>='D')){
				cout << '1';
				if((s1l=='D' and s2l=='F') or (s1l=='F' and s2l=='D')){
					cout << '1';
				}
				else if((s1l=='A' and s2l=='B') or (s1l=='B' and s2l=='A')){
					cout << '1';
				}
				else if((s1l=='A' and s2l=='B') or (s1l=='B' and s2l=='A')){
					cout << '1';
				}
				else if((s1l=='B' and s2l=='C') or (s1l=='C' and s2l=='B')){
					cout << '1';
				}
				else{
					cout << '0';
				}
			}
			else{
				cout << "00";
			}
			
		}

	}
	else{
		cout << "0000";
	}
	return 0;
}
