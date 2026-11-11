#include<iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin >> s1 >> t1 >> s2 >> t2;
    for(int i = 0;i < s1.size();i++){
        if(s1[i] != s2[i]){
            cout << "0000";
            return 0;
        }
    }
    for(int i = 0;i < 2;i++){
        if(t1[i] != t2[i]){
            cout << "1000";
            return 0;
        }
    }
    if(t1[2] == 'A'){
        if(t2[2] == 'B') cout << "1111";
        else if(t2[2] == 'C') cout << "1110";
        else cout << "1100";
    }
    else if(t1[2] == 'B'){
        if(t2[2] == 'A' || t2[2] == 'C') cout << "1111";
        else cout << "1100";
    }
    else if(t1[2] == 'C'){
        if(t2[2] == 'B') cout << "1111";
        else if(t2[2] == 'A') cout << "1110";
        else cout << "1100";
    }
    else if(t1[2] == 'D'){
        if(t2[2] == 'F') cout << "1111";
        else cout << "1100";
    }
    else if(t1[2] == 'F'){
        if(t2[2] == 'D') cout << "1111";
        else cout << "1100";
    }
    return 0;
}
