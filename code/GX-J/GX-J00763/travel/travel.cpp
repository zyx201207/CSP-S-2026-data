#include<bits/stdc++.h>
using namespace std;
int n=0;
int main(){
    feropen("travel.in","r",stdin);
    feropen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    for(int i = 1;i <= 1;i++){
        cin >> c1 >> s1 >> c2 >> s2;
    }
    if(c1 == c2){
        cout << "1";
        n = n + 1;
    }
    else{
        cout << "0000";
        return 0;
    }
    for(int i=0;i<=0;i++){
        if(s1[i] == s2[i]){
            if(s1[i+1] != s2[i+1]){
                cout << "0";
                break;
            }
            cout << "1";
            n = n + 1;

        }
        else{
            cout << "0";

        }
    }
    for(int i=2;i<=2;i++){
        if(n == 2 && s1[i] == s2[i]){
            cout << "1";
            break;
            }
        else{
            cout << "0";
            break;
            }
    }
    for(int i=2;i<=2;i++){
        if(s1[2] == 'A' && s2[2] == 'B'){
            cout << "1";}
        else if(s1[2] == 'B' && s2[2] == 'C'){
            cout << "1";}
        else if(s1[2] == 'D' && s2[2] == 'E'){
            cout << "1";}
        else{
            cout << "0";}
    }


    return 0;
}
