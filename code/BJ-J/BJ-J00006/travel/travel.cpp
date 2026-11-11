#include<bits/stdc++.h>
using namespace std;
void solved(){
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){
        cout << 1;
    }
    else{
        cout << "0000" << endl;
        return;
    }
    if(s2[0] == s4[0] && s2[1] == s4[1]){
        cout << 1;
    }
    else{
        cout << "000" << endl;
        return;
    }
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
        //cout << "abc" << endl;
        if(s4[2] ==  'D' || s4[2] == 'F'){
            cout << "00" << endl;
            return;
        }
        else cout << 1;
    }
    else{
        if(s4[2] == 'D' || s4[2] == 'F'){
            cout << 11 << endl;
            return;
        }
        else{
            cout << "00" << endl;
            return;
        }
    }
    if(s2[2] == 'A' || s2[2] == 'C'){
        if(s4[2] == 'B') cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    else{
        if(s4[2] == 'A' || s4[2] == 'C') cout << 1 << endl;
        else cout << 0 << endl;
    }
    return;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--) solved();
    return 0;
}
