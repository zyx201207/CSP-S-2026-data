#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int x1,y1,x2,y2;
    x1=(s1[0]-'0')*10+(s1[1]-'0');
    x2=(s2[0]-'0')*10+(s2[1]-'0');
    if(x1==x2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    y1=s1[2]-'A'+1;
    y2=s2[2]-'A'+1;
    if(y1<=3&&y2<=3){
        cout<<1;
        if((y1==y2+1)||(y1==y2-1)){
            cout<<1;
            return 0;
        }
        cout<<0;
    }
    else if(y1>3&&y2>3){
        cout<<1;
        if((y1==y2+1)||(y1==y2-1)){
            cout<<1;
            return 0;
        }
        cout<<0;
    }
    else {
        cout<<"00";
    }
    return 0;
}
