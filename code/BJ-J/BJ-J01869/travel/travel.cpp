#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int c,d;
    cin>>c>>a>>d>>b;
    if(c==d){
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<"1";
            if(a[2]=='F'||a[2]=='D'){
                if(b[2]=='F'||b[2]=='D'){
                    cout<<"11";
                }
                else{
                    cout<<"00";
                }
            }
            else{
                if(b[2]!='F'&&b[2]!='D'){
                    cout<<"1";
                    if(abs(int(b[2]-a[2]))==1){
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
                else{
                    cout<<"00";
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
