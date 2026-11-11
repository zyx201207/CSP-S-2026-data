#include <bits/stdc++.h>
using namespace std;
int main(){
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i = 1;i < s2.size() - 1;i++){
    	if(c1[i] == s1[i]){
        	cout << "1";
    	}
    	else{
    		cout << "0";
		}
		if(c2[i] == s2[i]){
			cout << "1";
		} 
		else{
			cout << "0";
		}
		if(c2[i] >= 'A' && c2[i] <= 'F' && s2[i] >= 'A' && s2[i] <= 'F'){
			cout << "1";
		}
		else{
			cout << "0";
		}
		if(c2[i] >= 'A' && c2[i] <= 'C' || c2[i] >= 'D' && c2[i] <= 'F' && s2[i] >= 'A' && s2[i] <= 'C' || s2[i] >= 'D' && s2[i] <= 'F'){
	    	cout << "1";
		}
		else{
			cout << "0";
		}	
	}
    return 0;
}
