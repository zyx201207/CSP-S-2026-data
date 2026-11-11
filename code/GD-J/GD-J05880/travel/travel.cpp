#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}else{
		cout << '1';
		for(int i=0;i<1;i++){
			if(s1[i]!=s2[i]){
				cout << "000";
				return 0; 
			}
		}
		cout << '1';
		if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C') || (s1[2]=='F' || s1[2]=='D') && (s2[2]=='F' || s2[2]=='D')){
			cout << '1';
		}else{
			cout << "00";
			return 0;
		}
		if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
			cout << '1';
		}else if(max(int(s1[2]),int(s2[2]))-min(int(s1[2]),int(s2[2]))==1){
			cout << '1';
		}else{
			cout << '0';
		}
	}
	return 0;
}
