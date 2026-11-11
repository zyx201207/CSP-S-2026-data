#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2;
    int b1,b2,p[3]={0,0,0};
    cin >>b1>>a1>>b2>>a2;
    if(b1 == b2){
        cout << 1;

        if(a1[2] >= 'D') p[0]=1;
        if(a2[2] >= 'D') p[1]=1;

        if(a1[0] == a2[0] && a1[1] == a2[1]){
            cout << 1;
            p[2] = 1;
            if(p[0]==p[1]){
                cout << 1;
            }else{
                cout << 0;
            }
        }else{
            cout << "00";
        }

        if(((a1[2]-1) == a2[2] || ((a1[2]+1) == a2[2])) && (p[0]==p[1] && p[2]==1)){
            cout <<1;
        }else if((p[0]==p[1] && p[2]==1) && (a1[2] == 'F' || a1[2] == 'D') && (a2[2] == 'F' || a2[2] == 'D')){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }else{
        cout <<"0000";
    }
    return 0;
}
