#include<bits/stdc++.h>
using namespace std;
int main(){
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1[0]==x1[0]){
        cout<<"1";
        }if(r1[1]==x1[1]){
        cout<<"1";
        }if(r2[0]==x2[0] && r2[1]==x2[1]){
        cout<<"1";
        }if(r2[2]==x2[2]){
        cout<<"1";
        }
    else{
        cout<<"0";
    }

return 0;
}
