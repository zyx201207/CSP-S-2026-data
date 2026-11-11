#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a,b,c,d;
    a=b=c=d=0;
    if(c1==c2){
        a=1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            b=1;
            if(int(s1[2]<='C') ^ int(s2[2]>='D')){
                c=1;
                if(abs(int(s2[2])-int(s1[2]))==1){
                    d=1;
                }
            }
        }
    }
    cout<<a<<b<<c<<d;

}
