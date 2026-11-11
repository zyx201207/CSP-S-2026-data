#include <bits/stdc++.h> 
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1;
	for(int i = 0;i< 3;i++){
		cin >> c2[i];
	}
	cin >> s1;
	for(int i = 0;i< 3;i++){
		cin >> s2[i];
	}
	if(c1 == s1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(c2[1]==s2[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C' && s2[2]=='A' || s2[2]=='B' || s2[2]=='C' &&c2[2]=='D' || c2[2]=='F' && s2[2]=='D' || s2[2]=='F' ){
	
		cout << 1;
		
		
	}
	
	else{
			cout << 0;
		
		}
	if(c2[2]=='A'  && s2[2]=='B' || c2[2]=='B' && s2[2]=='A'){
		
			cout << 1;
		}
		else if(c2[2]=='C'  && s2[2]=='B' || c2[2]=='B' && s2[2]=='C'){
		
			cout << 1;
		}
		else if(c2[2]=='D'  && s2[2]=='F' || c2[2]=='F' && s2[2]=='D'){
		
			cout << 1;
		}
		else if(c2[2]=='C'  && s2[2]=='D' || c2[2]=='D' && s2[2]=='C'){
		
			cout << 0;
		}
		else{
			cout << 0;
		}
	
	
	return 0;
}
