#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,w,e;
	string b ;
	string d,f,t,x;
	cin >> w >> a >> e >> b ;
	for(char c : a){
		if(c >= '0' && c <= '9'){
			d = c;
		}
		else{
			f = c;
		}
	}
	for(char s : b){
			if(s >= '0' && s <= '9'){
				t = s;
			}
			else{
				x = s;
			}
		}
	if(w != '01'&& e != '16'){
		cout << '1' ;
		if((t == d) && w==e ){
			cout << '1';
			if((f == 'D' && x == 'F')||
				(x == 'F' && f == 'D')||
				(f == 'B' && x == 'A')||
				(f == 'B' && x == 'C')||
				(f == 'A' && x == 'C')||
				(f == 'A' && x == 'B')||
				(f == 'C' && x == 'B')||
				(f == 'C' && x == 'A')||){
					cout << '1' ;
					if((f == 'C' && x == 'A')||(f == 'A' && x == 'C')){
						cout << '1' ;
					}
			}
		} 
	}else {
		cout << '0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
