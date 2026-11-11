#include<bits/stdc++.h>
#define int long long
using namespace std;
int n1,n2;
string s1,s2;

char ch[6] = {'/','A','B','C','D','F'};
int fl = 0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n1 >> s1 >> n2 >> s2;
	
	if(n1 != n2){
		cout << "0000" ;
		return 0;
	}
	else{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F')){
				cout << "1";
				for(int i = 1;i <= 4;i ++){
					if(i == 3) continue;
					if(s1[2] == ch[i] && s2[2] == ch[i + 1]){
						cout << "1";
						fl = 1;
						break;
					}
					if(s1[2] == ch[i + 1] && s2[2] == ch[i]){
						cout << "1";
						fl = 1;
						break;
					}
				}
				if(fl == 0){
					cout << "0" ;
				}
				
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
} 
