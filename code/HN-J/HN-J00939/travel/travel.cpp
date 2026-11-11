#include <bits/stdc++.h>

using namespace std;
int r,x;
string rs,xs;

/*bool ifrx(char rd;char xd){
    if((rd>='A' && rd<='C') && (xd>='A' && xd<='C')){
        return true;
    }else if((rd>='D' && rd<='F') && (xd>='D' && xd<='F')){
        return true;
    }else{
        return false;
    }
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>rs>>x>>xs;
    char rd=rs[2],xd=xs[2];
    if(r==x){
        cout<<"1";
        if(rs[0]==xs[0] && rs[1]==xs[1]){
            cout<<"1";
            if((rd>='A' && rd<='C') && (xd>='A' && xd<='C') || (rd>='D' && rd<='F') && (xd>='D' && xd<='F')){
                cout<<"1";
                if(rd-xd==1 || xd-rd==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
