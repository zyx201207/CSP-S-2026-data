#include<iostream>
using namespace std;
int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    int c1,c2;
    char s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1%10/10==s2%10/10){
            cout<<"1";
        }else{
            cout<<"0";
        }if(((s1%10<='C' || s1%10>='A') || (s2%10<='C' || s2%10>='A')) && ((s1%10=='F' &&  s1%10=='D')||(s2%10=='F' && s2%10=='D'))){
            cout<<"1";
        }else{
            cout<<"0";
        }if(s1%10+1==s2%10 && s1%10-1==s2 && s2%10+1==s1 && s2-1==s1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }
    return 0;
}
