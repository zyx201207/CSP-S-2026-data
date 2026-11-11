#include <bits/stdc++.h>
using namespace std;

string c1 , s1 , c2 , s2;
string s = "";

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2){
        s += "1";
    }else{
        s += "0000";
        cout << s << endl;
        return 0;
    }

    string s3 , s4;

    for(int i = 0 ; i < 2 ; i ++){
        s3 += s1[i];
        s4 += s2[i];
    }

    if(s3 == s4){
        s += "1";
    }else s += "0";

    char ch1 = s1[2];
    char ch2 = s2[2];

    if(s3 == s4){

        if(ch1 >= 'A' && ch1 <= 'C' && ch2 >= 'A' && ch2 <= 'C' ||
        ch1 == 'D' && ch2 == 'F' || ch1 == 'F' && ch2 == 'D'){
            s += "1";
        }else{
            s += "0";
        }
    }else s += "0";

    if(abs(int(ch1) - int(ch2)) == 1){
        if(ch1 == 'C' && ch2 == 'D' || ch1 == 'D' && ch2 == 'D'){
            s += "0";
        }
        else{
            s += "1";
        }
    }
    else{
        s += "0";
    }
    cout << s << endl;

	return 0;
}
