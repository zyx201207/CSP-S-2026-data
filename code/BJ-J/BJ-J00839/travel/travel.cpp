#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,a,b;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]*10+s1[1];
    b=s2[0]*10+s2[1];
    if(c1==c2){
        cout<<'1';
        if(a==b){
            cout<<'1';
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
                cout<<'1';
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }else {
        cout<<"0000";
        return 0;
    }

    return 0;
}
