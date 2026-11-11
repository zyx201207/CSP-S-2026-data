#include<bits/stdc++.h>
using namespace std;
int main (){
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1==c2){
    cout << "1";
     if(s1[1]==s2[1] && s1[2]==s2[2]){
        cout <<"1";
    if(s1[3]-s2[3]<=2 ){
    cout <<"1";
    if(s1[3]-s2[3]==1){
        cout <<"1";
    }else{
    cout <<"0";
    }
    }else{
    cout <<"0";
    }
    }else{
    cout << "0";
    }
    }else if(c1!=c2){
    cout << "0000";
    }




return 0;
}
