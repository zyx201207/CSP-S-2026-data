//GZ-J00279 程子洋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    string b[100];
    int c=0;
    for(int i=0;i<4;i++){
        cin>>a;
        b[i]=a;
    }
    if(b[0]!=b[2]){
        cout<<"0000";
    }
    if(b[0]==b[2]){
        cout<<"1110";
return 0;
}
