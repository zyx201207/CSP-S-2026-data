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
    cout<<"1";
    int a=(s1[0]-'0')*10+(s1[1]-'0');
    int b=(s2[0]-'0')*10+(s2[1]-'0');
    if(a!=b){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    int x=s1[2]-'A'+1;
    int y=s2[2]-'A'+1;
    if(x>y)swap(x,y);
    if(x<=3&&y>3){
       cout<<"00";
       return 0;
    }
    cout<<1;
    if(y-x!=1){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}
