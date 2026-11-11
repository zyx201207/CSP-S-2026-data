#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string tr_num1;
    string sit_num1;
    string tr_num2;
    string sit_num2;
    cin>>tr_num1>>sit_num1>>tr_num2>>sit_num2;
  // cout<<sit_num1[0]<<" "<<sit_num1[1]<<" "<<sit_num1[2]<<" "<<sit_num1[3]<<endl;
   //cout<<sit_num2[0]<<" "<<sit_num2[1]<<" "<<sit_num2[2]<<" "<<sit_num2[3]<<endl;
    if(tr_num1 == tr_num2) { //1
            cout<<"1";
    if(sit_num1[0]==sit_num2[0]&&sit_num1[1]==sit_num2[1]){ //2
        cout<<"1";
    } else cout<<"0";
    if(sit_num1[0]==sit_num2[0]&&sit_num1[1]==sit_num2[1]){ //3
        if(sit_num1[2]>='A'&&sit_num2[2]>='A'&&sit_num1[2]<='C'&&sit_num2[2]<='C'){
            cout<<"1";
        }
        else if(sit_num1[2]>='D'&&sit_num2[2]>='D'&&sit_num1[2]<='F'&&sit_num2[2]<='F') {
             cout<<"1";
        }
        else {
            cout<<"0";
        }
    } else cout<<"0";

    } else {
    cout<<"000";}
    bool flag = 0;
    if(sit_num1[0]==sit_num2[0]&&sit_num1[1]==sit_num2[1]){
    if(sit_num1[2]=='B'){
        if(sit_num2[2]=='A'||sit_num2[2]=='C') {
            cout<<"1";
            flag =1;

        }
    }
    else if(sit_num2[2]=='B'){
        if(sit_num1[2]=='A'||sit_num1[2]=='C') {
            cout<<"1";
            flag =1;
        }
    }
    else if(sit_num2[2]=='D'){
        if(sit_num1[2]=='F') {
            cout<<"1";
            flag =1;
        }
    }
    else if(sit_num1[2]=='D'){
        if(sit_num2[2]=='F') {
            cout<<"1";
            flag =1;
        }
    }

    }
    if(flag == 0) {cout<<"0";

    }


}
//02 01A 02 01B
