#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int X,R;
string x,r;
cin>>X>>x>>R>>r;
if(X==R)
{
    cout<<"1";
    if(x[0]+x[1]==r[0]+r[1])
    {
    cout<<"1";
        if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(r[2]=='A'||r[2]=='B'||r[2]=='C'))
        {
            cout<<"1";
            if(x[2]-r[2]==1||r[2]-x[2]==1)
            {
                cout<<"1";
            }else{
            cout<<"0";
            }

        }else if((x[2]=='D'||x[2]=='F')&&(r[2]=='D'||r[2]=='F'))
        {
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;

        }
    }else{
        cout<<"000";
        return 0;
    }

}
else
{
    cout<<"0000";
    return 0;
}
return 0;
}
