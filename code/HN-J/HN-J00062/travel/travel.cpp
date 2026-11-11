#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,a1=0,a2=0,b1=0,b2=0;
	cin >> c1>> s1 >> c2 >> s2;
	if(c1==c2){
		
		for(int i = 1;i<=18;i++){
			if(s1=='A'+i) a1= i;
			else if(s1=='B'+i) a1= i;
			else if(s1=='C'+i) a1= i;
			else if(s1=='D'+i) a1= i;
			else if(s1=='F'+i) a1= i;
			
		}
		for(int j = 1;j<=18;j++){
			if(s2=='A'+j) a2= j;
			else if(s2=='B'+j) a2= j;
			else if(s2=='C'+j) a2= j;
			else if(s2=='D'+j) a2= j;
			else if(s2=='F'+j) a2= j;
			
		}
		if(a1==a2){ 
			
			if(s1=='A'+a1||s1=='B'+a1||s1=='C'+a1) b1=1;
			else b1 = 0;
			if(s2=='A'+a2||s2=='B'+a2||s2=='C'+a2) b2=1;
			else b2 = 0;
			if(b1==b2){
				
				if(s1 == 'A'+a1 && s2=='B'+a2 || s2=='A'+a2 && s1=='B'+a1 || s1=='B'+a1 && s2=='C'+a2 || s1=='C'+a1 && s2=='B'+a2 || s1=='D'+a1 && s2=='F'+a2 || s2=='D'+a2 && s1=='F'+a1) cout << 1111;
				else cout << 1110;
			}
			else cout << 1100;
		}
		else cout << 1000;
		
	}
	else cout << 0000;
	return 0;
} 
