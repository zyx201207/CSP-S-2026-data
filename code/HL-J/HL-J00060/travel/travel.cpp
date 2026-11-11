#include<bits/stdc++.h>
using namespace std;
string xl[] = {"bc","ac","b","f","d"};
string tp[] = {"bc","ac","ab","f","d"};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){
        cout << '1';
        string s2che_id=s2.substr(0,2);
        string s4che_id=s4.substr(0,2);
        if(s2che_id == s4che_id){
            cout << '1';
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C'){
                    cout << '1';
                    if(s2[2] == 'A' && s4[2] == 'B') cout << '1';
                    else if(s2[2] == 'B' && (s4[2] == 'A' || s4[2] == 'C')) cout << '1';
                    else if(s2[2] == 'C' && s4[2] == 'B') cout << '1';
                    else if(s2[2] == 'D' && s4[2] == 'F') cout << '1';
                    else if(s2[2] == 'F' && s4[2] == 'D') cout << '1';
                    else cout << '0';
                }else cout << "00";
            }
        }else cout << "000";
    }else{
        cout << "0000";
    }
    return 0;
}
