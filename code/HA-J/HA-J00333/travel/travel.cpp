#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	st n1,n2;
	st s1,s2;
	cin >> n1 >> s1 >> n2 >> s2;
	if(n1==n2){
		cout << "1";
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout << "1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout << "1";
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					cout << "1";
				}
				else
				cout << "0";
			}
			else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
				cout << "11";
			}
			else{
				cout << "00";
			}
		}
		else
		cout << "000";
	}
	else
	cout << "0000";
	return 0;
}
