#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h,s;
	int z,c,S,H;
	int toto=1;
	cin >> c >> s >> z >> h;
	S=s[0]+s[1];
	H=h[0]+h[1];
    if(c==z) cout << 1;
    else cout << 0;	toto=0;
	if(S==H && toto!=0) cout << 1;
	else cout << 0;	toto=0;
	
	if(s[2]=='A'&& toto!=0){
    	if(h[2]=='B' || h[2]=='C'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='B'&& toto!=0){
    	if(h[2]=='A' || h[2]=='C'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='C'&& toto!=0){
    	if(h[2]=='A' || h[2]=='B'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='D'&& toto!=0){
    	if(h[2]=='F'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='F'&& toto!=0){
    	if(h[2]=='D'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else cout << 0;
	if(s[2]=='A'&& toto!=0){
    	if(h[2]=='B'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='B'&& toto!=0){
    	if(h[2]=='A' || h[2]=='C'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='C'&& toto!=0){
    	if(h[2]=='B' || h[2]=='D'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='D'&& toto!=0){
    	if(h[2]=='C' || h[2]=='F'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else if(s[2]=='F'&& toto!=0){
    	if(h[2]=='D'){
    		cout << 1;
		}
		else cout << 0; toto=0;
	}
	else cout << 0;
	return 0;
}





