#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a1=s1[0];
	char b1=s1[1];
	char cr=s1[2];
	char a2=s2[0];
	char b2=s2[1];
	char cx=s2[2];
	
	if(c1==c2){
		cout << 1;
	}else{
		cout << 0;
	}
	
	if(c1==c2){
		if(a1==a2&&b1==b2){
		cout << 1;
		if(cr=='A'&&cx=='B' || cr=='A'&&cx=='C' || cr=='B'&&cx=='A' || cr=='B'&&cx=='C' || cr=='C'&&cx=='B' || cr=='C'&&cx=='A'||cr=='D'&&cx=='F' || cr=='F'&&cx=='D'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	}
	
	
	if(c1==c2){
			if(a1==a2&&b1==b2){
		if(cr=='A'&&cx=='B' || cr=='B'&&cx=='A' || cr=='B'&&cx=='C' || cr=='C'&&cx=='B' || cr=='D'&&cx=='F' || cr=='F'&&cx=='D'){
			cout << 1;
		}else{
			cout << 0; 
		}
	}
	
	}

	
	return 0;
}
