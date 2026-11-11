#include <bits/stdc++.h>
using namespace std;
int tong[200];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    tong['D']=tong['F']=1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string result="";
    if(c1!=c2) result+="0000";
    else{
        result+="1";
        string p1=s1.substr(0,2);
        string p2=s2.substr(0,2);
        if(p1!=p2) result+="000";
        else{
            result+="1";
            if(tong[s1[2]]!=tong[s2[2]]) result+="00";
            else{
                result+="1";
                if(abs((int)s1[2]-(int)s2[2])!=1) result+="0";
                else result+="1";
            }
        }
    }
    cout<<result;
    return 0;
}
