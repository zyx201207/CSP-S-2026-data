#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int a=0,b=0,c1,c2;
    cin >> c1 >> s1 >>c2>> s2;
    if (c1==c2){
        cout << "1";
    }else{
        cout << "0";
    }
    if (s1[0]==s2[0] && s1[1]==s2[1]){
        cout << "1";
    }else{
        cout << "0";
    }
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
        a=1;
    }
    if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
        b=1;
    }
    if (a==b){
        cout << "1";
    }else{
        cout << "0";
    }
    if (((b==1&&s1[2]=='B') || ((s1[2]=='A' || s1[2]=='C') && s2[2]=='B')) || (a==b &&b==0)){
        cout <<"1";
    }else{
        cout <<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
