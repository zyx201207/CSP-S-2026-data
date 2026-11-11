#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int arr;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(c1[0]==c2[0]){
            if(c1[1]==c2[1]){
                cout<<"1";
            }else{
                cout<<"0";
                arr = 0;
            }
        }else{
            cout<<"0";
            arr = 0;
        }
        if(arr==0){
        cout<<"0";
        }else{
            cout<<"1";
        }
        if(s1[2]+1==s2[2]){
            cout<<"1";
        }else if(s2[2]+1==s1[2]){
            cout<<"1";
        }else{
            cout<<"0";
        }

    }else{
        cout<<"0000";
    }
    return 0;
}
