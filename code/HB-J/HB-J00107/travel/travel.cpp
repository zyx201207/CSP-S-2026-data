#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int get(string s){
    int res=0;
    for(int i=0;i<s.size();i++){
        res=res*10+(s[i]-'0');
    }
    return res;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    int a1,b1,p1,a2,b2,p2;
    a1=get(c1);b1=get(s1.substr(0,2));p1=s1[2]-'A'+1;
    a2=get(c2);b2=get(s2.substr(0,2));p2=s2[2]-'A'+1;
    if(a1==a2){
        cout<<"1";
        if(b1==b2){
            cout<<"1";
            if((p1<=3&&p2<=3)||(p1>3&&p1>3)){
                cout<<"1";
                if(abs(p1-p2)==1){
                    cout<<"1";
                    return 0;
                }else{
                    cout<<"0";
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
}