#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int a=0,b=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
    if(s2[2]>='A'&&s2[2]<='C') a=1;
    if(t2[2]>='A'&&t2[2]<='C') b=1;
    if(s1==t1)
    {
        cout<<1;
        if(s2[0]==t2[0]&&s2[1]==t2[1])
        {
            cout<<1;
            if(a==b)
            {
                cout<<1;
                if(a==0||int(s2[2]-t2[2])==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
