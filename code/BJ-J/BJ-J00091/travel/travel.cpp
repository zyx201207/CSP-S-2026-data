#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;string z1,z2;
    cin>>c1>>z1>>c2>>z2;
    int zw1,zw2;
    if(c1==c2)
    {
        cout<<1;
        if(z1[0]+z1[1]==z2[0]+z2[1])
        {
            cout<<1;
            if(!((z1[2]=='A'||z1[2]=='B'||z1[2]=='C')^(z2[2]=='A'||z2[2]=='B'||z2[2]=='C'))){
                cout<<1;
                switch(z1[2]){
                    case 'A':
                        zw1=1;break;
                    case 'B':
                        zw1=2;break;
                    case 'C':
                        zw1=3;break;
                    case 'D':
                        zw1=5;break;
                    case 'E':
                        zw1=6;break;
                    default:
                        break;
                }
                switch(z2[2]){
                    case 'A':
                        zw2=1;break;
                    case 'B':
                        zw2=2;break;
                    case 'C':
                        zw2=3;break;
                    case 'D':
                        zw2=5;break;
                    case 'E':
                        zw2=6;break;
                    default:
                        break;
                }
                if(zw1-zw2==1||zw1-zw2==-1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
