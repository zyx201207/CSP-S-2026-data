#include <bits/stdc++.h>
using namespace std;
int c1,c2,b1,b2,b;
char d1,d2,c;
string s1,s2,a;
void arr(string a,int b,char c='A'){
    for(c;c<'G';c++){
            a=c;
            cout << a;
            for(b;b<16;b++){
                if (s1==a){
                        b1=b;
                        d1=c;
                }
                else if(s2==a){
                        b2=b;
                        d2=c;
                }
            }
    }
    if(d1==d2){
                cout << "1";
    }
    else{
            cout << "0";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    arr(a,b,c);
    cout <<a;
    return (0);
}
