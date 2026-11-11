#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,s1,s2;
    cin>>s1>>a>>s2>>b;
    //cout<<a<<" "<<s1<<" "<<b<<" "<<s2;
    if(s1==s2)
    {
        cout<<1;
        if(a[0]==b[0]&&a[1]==b[1])
        {
            cout<<1;
            if((a[2]<='C'&&b[2]<='C'||a[2]>'C'&&a[2]<='F'&&b[2]>'C'&&b[2]<='F')&&a[2]!='E'&&b[2]!='E')
            {
                cout<<1;
                if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[2]=='A'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')
                {
                    cout<<1;
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
