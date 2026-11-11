#include<bits/stdc++.h>
using namespace std;
int f1,f2,f3,f4;
string c1,s1,c2,s2;
string x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    x = s1[0];
    x = x +s1[1];
    y = s2[0];
    y = y +s2[1];
    if(c1==c2){
        f1=1;
    }else{
        cout << "0000" ;
        return 0;
    }
    if(x==y){
        f2=1;
    }else{
        cout << "1000";
        return 0;
    }
    x = s1[2];
    y = s2[2];
    if(x == "A" || x == "B" || x == "C"){
        if(y == "A" || y == "B" || y == "C"){
            f3=1;
            if(x == "A" && y == "B"
               || x == "B" && y == "A"
               || x == "B" && y == "C"
               || x == "C" && y == "B"){
                f4=1;
               }
        }
    }else if(x == "D" || x=="F"){
        if(y == "D" || y == "F"){
            f3=1;
            if(x == "D" && y == "F"
               || x == "F" && y == "D"){
                f4=1;
               }
        }
    }
    cout << f1<< f2<< f3<< f4;
    return 0;
}
