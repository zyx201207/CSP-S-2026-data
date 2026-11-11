#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a=0,b=0,c=0,d=0,t1,t2;
    a=(c1==c2);
    b=(a&&s1[0]==s2[0]&&s1[1]==s2[1]);
    if(s1[2]>='D'){
        t1=1;
    }else{
        t1=0;
    }
    if(s2[2]>='D'){
        t2=1;
    }else{
        t2=0;
    }
    c=(a&&b&&t1==t2);
    d=(a&&b&&c&&abs(int(s1[2]-s2[2]))==1);
    cout<<a<<b<<c<<d;

    return 0;
}
