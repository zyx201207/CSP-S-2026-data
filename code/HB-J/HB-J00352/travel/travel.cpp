#include <bits/stdc++.h>

using namespace std;
map<string,bool> m;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    m["AB"]=true;
    m["AC"]=true;
    m["AD"]=false;
    m["AE"]=false;
    m["BC"]=true;
    m["BA"]=true;
    m["BD"]=false;
    m["BE"]=false;
    m["CA"]=true;
    m["CB"]=true;
    m["CD"]=false;
    m["CE"]=false;
    m["DA"]=false;
    m["DB"]=false;
    m["DC"]=false;
    m["DE"]=true;
    m["EA"]=false;
    m["EB"]=false;
    m["EC"]=false;
    m["ED"]=true;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            string temp="";
            temp+=s1[2];
            temp+=s2[2];
            if(m[temp]){
                cout<<1;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
}
