#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int cnt=0;
	cin >> c1>>s1>>c2>>s2;
	if(c1==c2){
		cnt++;
		cout <<1;
	}
	else	cout <<'0';
	if(s1[0]==s2[0] && s1[1] == s2[1]){
		cout <<1;
		cnt++;
	}
	else{
		cout << '0';
	}
	if((s1[2] =='D' || s1[2]=='F') && cnt==2){
			if(s2[2] != 'D' && s2[2] !='F'){
				cout <<'0';
				cnt++;
			}
			else{
				cout <<1;
				cnt++;
			}
		}
	if((s1[2] =='A' || s1[2]=='B' || s1[2] == 'C') && cnt==2){
			if(s2[2] != 'A' && s2[2] !='B' && s2[2] != 'C'){
				cout <<'0';
			}
			else{
				cout <<1;
				cnt++;
			}
		}
	if((s1[2] == s2[2]+1 || s1[2] == s2[2]-1) && cnt==3)	cout <<1;
	else	cout <<'0';
	
	
	return 0;
}