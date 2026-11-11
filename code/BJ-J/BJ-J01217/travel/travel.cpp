#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(int st1,int st2){
    if(st1<='C' && st2<='C'){
        return true;
    }
    if(st1>='D' && st2>='D'){
        return true;
    }
    if((st1<='C'&&st2>='D')  || st2<='C'&&st1>='D'){
        return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 != c2){
        cout<<"0000";
        return 0;
    }
    else{
        int pai1=s1[0]+s1[1];
        int pai2=s2[0]+s2[1];
        if(pai1 != pai2){
            cout<<1000;
            return 0;
        }
        else{
            int st1=s1[2];
            int st2=s2[2];
            if(check(st1,st2)){
                if(abs(st1-st2) == 1){
                   cout<<1111;
                   return 0;
                }
                else{
                    cout<<1110;
                    return 0;
                }
            }
            else{
                cout<<1100;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}