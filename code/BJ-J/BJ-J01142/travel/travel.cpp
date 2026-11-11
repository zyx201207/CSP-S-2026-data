#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,s1,c2,s2,z1,z2;
char w1,w2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    c1=(a[0]-'0')*10+a[1]-'0';
    s1=(b[0]-'0')*10+b[1]-'0';
    c2=(c[0]-'0')*10+c[1]-'0';
    s2=(d[0]-'0')*10+d[1]-'0';
    w1=b[2];
    w2=d[2];
    if(c1==c2)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s1==s2)cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(w1-'A'<3)z1=1;
    else z1=2;
    if(w2-'A'<3)z2=1;
    else z2=2;
    if(z1==z2){
        cout<<"1";
        if(z1==1){
            if(w1-w2==1||w1-w2==-1)cout<<"1" ;
            else cout<<"0";
        }else{
            cout<<"1" ;
            
        }
    }else{
        cout<<"00";
    }
    return 0;
}
