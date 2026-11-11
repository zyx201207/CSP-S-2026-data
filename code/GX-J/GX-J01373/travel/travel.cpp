#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int f=0;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        f ++;
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            cout<<1;
            f ++;
            if(s1[2]/int('D')==s2[2]/int('D')){
                cout<<1;
                f++;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                    f++;
                }
            }
        }
    }
    for(int i=1;i<=(4-f);i++){
        cout<<0;
    }

    return 0;
}
