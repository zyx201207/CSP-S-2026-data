#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
		cout << "1";
		if((s1[0] == s2[0]) && (s1[1] == s2[1])){
			cout << "1";
			int n, n2;
			if(s1[2] == 'A') n = 1; else if(s1[2] == 'B') n = 2; else if(s1[2] == 'C') n = 3; else if(s1[2] == 'D') n = 4; else if(s1[2] == 'F') n = 5;
			if(s2[2] == 'A') n2 = 1; else if(s2[2] == 'B') n2 = 2; else if(s2[2] == 'C') n2 = 3; else if(s2[2] == 'D') n2 = 4; else if(s2[2] == 'F') n2 = 5;
			if((n <= 3 && n2 <= 3) || (n >= 4 && n2 >= 4)){
				cout << "1";
				if((n - n2 == 1) || (n2 - n == 1)){
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000"; 
		}
	
	}
    else{
        cout << "0000";
    }

    fclose(stdin);
    fclose(stdout);


    return 0;
}
