#include<bits/stdc++.h>
using namespace std;
const string a="ABC";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout << 1;
			int s11=0,s22=0;
		for(int i=0;i<3;i++){
			if(a[i]==s1[2])s11=1;
			if(a[i]==s2[2])s22=1;
		}
		if((s11==1 and s22==1)or(s11==0 and s22==0)){
			cout << 1;
			if(s1[2]==s2[2]+1 or s1[2]==s2[2]-1){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			cout << 00;
		}
		}else{
			cout << 000;
		}
	}else{
		cout << 0000;
	}
	return 0;
}
        
