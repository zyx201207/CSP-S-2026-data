#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool s=true,c=true,x=false,y=false;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i])c=false;
        if(s1[i]!=s2[i])s=false;
    }
    if(s1[2]<='C'&&s2[2]<='C'){
        x=true;
        if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)y=true;
    }else if(s1[2]<='F'&&s1[2]>'C'&&s2[2]>'C'&&s2[2]<='F'){
        x=true;
        y=true;
    }
    cout<<c;
    if(c==true){
        cout<<s;
        if(s==true){
            cout<<x<<y;
        }else cout<<"00";
    }else cout<<"000";
    return 0;
}
