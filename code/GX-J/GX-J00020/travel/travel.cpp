#include<bits/stdc++.h>
using namespace std;
short r[2],x[2];
char rz,xz;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r[0]>>r[1]>>rz>>x[0]>>x[1]>>xz;
    if(r[0]==x[0]){
        cout<<'1';
        if(r[1]==x[1]){
            cout<<'1';
            if(rz<'D'&&xz<'D'||rz>='D'&&xz>='D'){
                cout<<'1';
                if(abs(rz-xz)==1)cout<<'1';
                else cout<<'0';
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
