#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string rp,xp;
int rzw,xzw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool isp=1;
	for(int i=0;i<2;i++){
		rp[i]=s1[i]-'0';
		xp[i]=s2[i]-'0';
		if(rp[i]!=xp[i]){
			isp=0;
		}
	}
	if(s1[2]>='A'&&s1[2]<='C'){
		rzw=1;
	}else{
		rzw=2;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		xzw=1;
	}else{
		xzw=2;
	}
	if(c1==c2){
		cout << 1;
	}else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(isp==1){
		cout << 1;
	}else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(rzw==xzw){
		cout << 1;
	}else{
		cout << 0 << 0;
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		if(s2[2]=='D')cout << 1;
		else cout << 0;
	}
	return 0;
}
