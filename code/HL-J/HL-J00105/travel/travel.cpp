#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    
    if(c1 == c2){
    	cout << 1;
    	
    	int t_1, t_2;
		t_1 = s1[0] * 10 + s1[1];
		t_2 = s2[0] * 10 + s2[1];
	
		if(t_1 == t_2){
    		cout << 1;
    	
    		if(((s1[2] == 'A') && (s2[2] == 'B')) || ((s1[2] == 'B') && (s2[2] == 'A')) || ((s1[2] == 'B') && (s2[2] == 'C')) || ((s1[2] == 'C') && (s2[2] == 'B')) || ((s1[2] == 'A') && (s2[2] == 'C')) || ((s1[2] == 'C') && (s2[2] == 'A')) || ((s1[2] == 'D') && (s2[2] == 'F')) || ((s1[2] == 'F') && (s2[2] == 'D'))) {
				cout << 1;
			}else{
        		cout << 0;
    		}

			if(((s1[2] == 'A') && (s2[2] == 'B')) || ((s1[2] == 'B') && (s2[2] == 'A')) || ((s1[2] == 'B') && (s2[2] == 'C')) || ((s1[2] == 'C') && (s2[2] == 'B')) || ((s1[2] == 'D') && (s2[2] == 'F')) || ((s1[2] == 'F') && (s2[2] == 'D'))) {
				cout << 1;
			}else{
        		cout << 0;
    		}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
    return 0;
}
