#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    long long len1 = c1.length();
    long long len2 = c2.length();
    long long x1 = 0,x2 = 0;
    char a1,a2;
    for(int i = 0; i < s1.length(); i++){
    	if(s1[i] >= '0' && s1[i] <= '9'){
    		x1 = x1 * 10 + s1[i];
		}
		else if(i == s1.length() - 1){
			a1 = s1[i];
		}
	}
	for(int i = 0; i < s2.length(); i++){
    	if(s2[i] >= '0' && s2[i] <= '9'){
    		x2 = x2 * 10 + s2[i];
		}
		else if(i == s2.length() - 1){
			a2 = s2[i];
		}
	}
	if(len1 == len2){
		cout << "1";
		if(x1 == x2){
		cout << "1";
		    if(((a1 >= 'A' && a1 <= 'C') && (a2 >= 'A' && a2 <= 'C')) || ((a1 == 'D' || a1 == 'F') && (a2 == 'D' || a2 == 'F'))){
		    	cout << "1";
		    	if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "0";
				if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
	    }
	    else{
		cout << "0";
		    if(((a1 >= 'A' && a1 <= 'C') && (a2 >= 'A' && a2 <= 'C')) || ((a1 == 'D' || a1 == 'F') && (a2 == 'D' || a2 == 'F'))){
		    	cout << "1";
		    	if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "0";
				if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
	    }
	}
	else{
		cout << "0";
		if(x1 == x2){
		cout << "1";
		if(((a1 >= 'A' && a1 <= 'C') && (a2 >= 'A' && a2 <= 'C')) || ((a1 == 'D' || a1 == 'F') && (a2 == 'D' || a2 == 'F'))){
		    	cout << "1";
		    	if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "0";
				if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
			}
	    }
	    else{
		cout << "0";
		if(((a1 == 'A' && a2 == 'B') || (a1 == 'B' && a2 == 'A')) || ((a1 == 'B' && a2 == 'C') || (a1 == 'C' && a2 == 'B')) || ((a1 == 'D' && a2 == 'E') || (a1 == 'E' && a2 == 'D'))){
		    		cout << "1";
				}
				else{
					cout << "0";
				}
				
	    }
	}
	return 0;
} 
