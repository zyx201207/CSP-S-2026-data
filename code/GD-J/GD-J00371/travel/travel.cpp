#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char t1,t2;
int a1,a2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		for(int i = 0;i <= 1;i++){
			a1 = a1*10+(s1[i]-'0');
			a2 = a2*10+(s2[i]-'0');
		}
		if(a1==a2){
			cout << 1;
			t1 = s1[2];
			t2 = s2[2];
			if((t1 >= 'A' && t1 <= 'C' && t2 >= 'A' && t2 <= 'C') || (t1 >= 'D' && t1 <= 'F' && t2 >= 'D' && t2 <= 'F')){
				cout << 1;
				if((t1 == 'D' || t1 == 'F') && (t2 == 'D' || t2 == 'F')){
					cout << 1;
				}else if(((t1 == 'A' || t1 == 'B') && (t2 == 'A' || t2 == 'B')) || ((t1 == 'B' || t1 == 'C') && (t2 == 'B' || t2 == 'C'))){
					cout << 1;
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
