#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string c2;
    string s1;
    string s2;
    cin >> c1;
    cin >> c2;
    cin >> s1;
    cin >> s2;
    if(s1 == c1){
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }

    for(int i = 0; i <= 1; i++){
        if(s2[i] != c2[i]){
            cout << "000";
            return 0;
        }
    }
    cout << "1";
    if(s2[2] <= 'C' && c2[2] <= 'C'){
        cout << "1";
    }else if(s2[2] > 'C' && c2[3] > 'C'){
        cout << "1";
    }else{
        cout <<0;
    }
    if(s2[2] - c2[2] == 1 && ( (s2[2] != 'D' && s2[2] != 'C') ||(c2[2] != 'D' && c2[2] != 'C'))){
        cout << "1";
    }else{
        cout << "0";
    }

    return 0;
}
