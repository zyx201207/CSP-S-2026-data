#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    char c1, c2;
    char s1, s2;

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2){
        cout << "1";
    }else{
        cout << "0";
    }

    char a = s1 -'A' && 'F';

    char a3 = s2 - 'A'&&'F';

    if(c1 == c2 && a == a3){
        cout << "1";
    }else{
        cout << "0";
    }

    char ding = s1 - '1' && '17';

    char ding2 = s2 - '1' && '17';

    if(c1 == c2 && a == a3 && (ding != 'C' && ding2 != 'D') || (ding != 'D' && ding2 != 'C')){
        cout << "1";
    }else{
        cout << "0";
    }



    if((ding - '1' == ding2 || ding + '1' == ding2) && (a == a3) && (ding != 'C' && ding2 != 'D') || (ding != 'D' && ding2 != 'C')){

        cout << "1";
    }else{
        cout << "0";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
