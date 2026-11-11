#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    int s1{A,B,C,D,F};
    int s2{A,B,C,D,F};
    cin>>c1>>s1>>c2>>s2;

    for(int i=2;i<=17;i++){
        if(c1!=16){
            if(s1!=s2){
                cout<<"1100"
            }
            else{
                cout<<"1000";
            }
        }
        else{
            cout<<"0000";
        }
    }

    return 0;
}
