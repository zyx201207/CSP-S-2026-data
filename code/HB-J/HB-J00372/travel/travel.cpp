#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    
   
    if(c1 == c2) cout << "1";
    else{
		cout << "0000";
		return 0;
	} 



    string t1 = s1.substr(0,2),t2 = s2.substr(0,2);
    if(t1 == t2) cout << "1";
    else cout << "0";

 

    char a = s1[2],b = s2[2];
    if(a == 'D' || a == 'F') a = '1';
    else a = '2';
    if(b == 'D' || b == 'F') b = '1';
    else b = '2';

    if(a == b && t1 == t2) cout << "1";
    else cout << "0";




    a = s1[2],b = s2[2];
    if(t1 == t2){
		if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')) cout << '1';
		else if((a == 'C' && b == 'B') || (a == 'B' && b == 'C') || (a == 'B' && b == 'A') || (a == 'A' && b == 'B'))
			cout << '1';
		else cout << '0';
	}
    else cout << '0';

    return 0;
}
