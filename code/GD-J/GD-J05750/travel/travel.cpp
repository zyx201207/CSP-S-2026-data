#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,pd="0000",zw1,zw2;
    cin>>c1>>s1>>c2>>s2;
    zw1=s1[2];
    zw2=s2[2];
    if(c1==c2){
        pd="1000";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            pd="1100";
            if((zw1>="A"&&zw1<="C"&&zw2>="A"&&zw2<="C")||((zw1=="D"&&zw2=="F")||(zw1 =="F"&&zw2=="D"))){
                pd="1110";
                if(zw1>="A"&&zw1<="C"&&zw2>="A"&&zw2<="C"){
                    if(zw1=="A"&&zw2=="B"||zw1=="B"&&zw2=="A"||zw1=="B"&&zw2=="C"||zw1=="C"&&zw2=="B"){
                        pd="1111";
                    }
                    else if((zw1=="D"&&zw2=="F")||(zw1 =="F"&&zw2=="D")){
                        pd="1111";
                    }
                }
            }
        }
    }
    cout<<pd;
    return 0;
}

