#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int s1,s2;
char s11,s22;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> s11 >> c2 >> s2 >> s22;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << "0";
    }
    if(c1 == c2 && s1 == s2){
        cout << 1;
    }
    else{
        cout << "0";
    }
    if(c1 == c2 && s1==s2){
        if(s11 == 'A'&&s22 == 'B'||s11 == 'A'&&s22 == 'C'||s11 == 'B'&&s22 =='C'||s11 == 'B'&&s22 == 'A'||s11 == 'A'&&s22 == 'C'||s11 == 'C'&&s22 == 'A'||s11 == 'D'&&s22 == 'F'||s11 == 'F'&&s22 == 'D'){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    if(c1 == c2 && s1==s2){
        if(s11 == 'A'&&s22 == 'B'||s11 == 'B'&&s22 == 'C'||s11 == 'D'&&s22 == 'F'||s11 == 'B'&&s22 == 'A'||s11 == 'B'&&s22  =='C'||s11 == 'F'&&s22 == 'D'){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
