#include<bits/stdc++.h>
using namespace std;
string cr,cx;
string sr,sx;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    int n=0,m=0;
    n=(cr[0]-'0')*10+(cr[1]-'0');
    m=(cx[0]-'0')*10+(cx[1]-'0');
    if(n!=m){
       cout<<"0000";
       return 0;
    }
    cout<<1;
    n=(sr[0]-'0')*10+(sr[1]-'0');
    m=(sx[0]-'0')*10+(sx[1]-'0');
    if(n!=m){
       cout<<"000";
       return 0;
    }
    cout<<1;
    int a,b;
    a=sr[2]-'A';
    b=sx[2]-'A';
    if((abs(a-b)>2)||(a==2&&b==3)||(a==3&&b==2)||(a==1&&b==3)||(a==3&&b==1)||(a==2&&b==4)||(a==4&&b==2)){
       cout<<"00";
       return 0;
    }
    cout<<1;
    if(abs(a-b)>1||(a==2&&b==3)||(a==3&&b==2)){
       cout<<0;
    }
    else cout<<1;
    return 0;
}