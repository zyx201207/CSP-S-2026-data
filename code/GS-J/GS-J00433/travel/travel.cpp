#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
bool f = false;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << 1;
	else cout << 0;
	
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
		f = true;	
	}
	else cout << 0;
	
	if(f && ((s1[2] <= 'C' && s2[2] <= 'C')||(s1[2] >= 'D' && s2[2] >= 'D'))){
		cout << 1;
	}
	else cout << 0;
	
	if((c1 == c2) && f){
		if(s1[2] <= 'C' && s2[2] <= 'C' && abs(s1[2]-s2[2]) == 1){
			cout << 1;
		}
		else if(s1[2] >= 'D' && abs(s1[2]-s2[2])==1){
			cout << 1;
		}
		else cout << 0;
	}
	else cout << 0;
	
	return 0;
}

