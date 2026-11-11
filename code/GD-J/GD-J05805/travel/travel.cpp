#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	string c1,s1,c2,s2;int a1=0,a2=0,a3=0,a4=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		a1 = 1;
	}
	if(s1[0] == s2[0]){
		if(s1[1] == s2[1]){
			a2 = 1;
			if(((s1[2] == 'A') && (s2[2] == 'B')) || ((s1[2] == 'B') && (s2[2] == 'A')) || ((s1[2] == 'B') && (s2[2] == 'C') || ((s1[2] == 'C') && (s2[2] == 'B'))) || ((s1[2] == 'D') && (s2[2] == 'F') || ((s1[2] == 'F') && (s2[2] == 'D')))){
				a4 = 1;
			}
			for(char i='A';i<='C';i++){
				if(s1[2] == i)
					for(char i='A';i<='C';i++)
						if(s2[2] == i)
							a3 = 1;
						
					
				
				else{
					if(((s1[2] == 'D') || (s1[2] == 'F')) && ((s2[2] == 'D') || (s2[2] == 'F'))){
						a3 = 1;
					}
					
				}
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	
	
	
	return 0;
} 
