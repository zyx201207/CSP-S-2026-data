#include <iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    bool x[4]={};
    {
        if(s1==s3)
            x[0]=true;
        else
            goto ex;
        if(s2.substr(0,2)==s4.substr(0,2))
            x[1]=true;
        else
            goto ex;
        if(s2[2]<='C'&&s4[2]<='C')
            x[2]=true;
        else if(s2[2]>'C'&&s4[2]>'C')
            x[2]=true,x[3]=true;
        else
            goto ex;
        if(s2[2]<='C'&&s4[2]<='C'&&abs(s2[2]-s4[2])==1)
            x[3]=true;
    }
    ex:
    for(int i=0;i<4;i++)
        cout<<x[i];
    return 0;
}
