#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    if(x1!=x3)cout<<"0000";
    else{
        cout<<1;
        if(!(x2[0]==x4[0]&&x2[1]==x4[1]))cout<<"000";
        else{
            cout<<1;
            if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
                if(!(x4[2]=='A'||x4[2]=='B'||x4[2]=='C')){
                    cout<<"00";
                }
                else{
                    cout<<1;
                    if(x2[2]=='A'){
                        if(x4[2]!='B')cout<<0;
                        else cout<<1;
                    }
                    else if(x2[2]=='B'){
                        if(x4[2]!='A'&&x4[2]!='C')cout<<0;
                        else cout<<1;
                    }
                    else{
                        if(x4[2]!='B')cout<<0;
                        else cout<<1;
                    }
                }
            }
            else{
                if((x4[2]=='A'||x4[2]=='B')||x4[2]=='C'){
                    cout<<"00";
                }
                else{
                    cout<<1;
                    if(x2[2]=='D'){
                        if(x4[2]!='F')cout<<0;
                        else cout<<1;
                    }
                    else{
                        if(x4[2]!='D')cout<<0;
                        else cout<<1;
                    }
                }
            }
        }
    }
    return 0;
}
