#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,h1,h2;
    char l1,l2;
    cin>>c1>>h1>>l1;
    cin>>c2>>h2>>l2;
    if(c1==c2){
        cout<<1;
        if(h1==h2){
            cout<<1;
            if( (\
                    (l1=='A'||l1=='B'||l1=='C')&&\
                    (l2=='A'||l2=='B'||l2=='B')\
                )||(\
                    (l1=='D'||l1=='F')&&\
                    (l2=='D'||l2=='F')\
                )   ){
                cout<<1;
                if( (l1=='A'&&l2=='B')||\
                    (l1=='B'&&l2=='C')||\
                    (l1=='D'&&l2=='F')||\
                    (l1=='B'&&l2=='A')||\
                    (l1=='C'&&l2=='B')||\
                    (l1=='F'&&l2=='D')  ){
                    cout<<1;
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";

    return 0;
}
/*
    (\
        (l1=='A'||l1=='B'||l1=='C')&&\
        (l2=='A'||l2=='B'||l2=='B')\
     )||(\
    (l1=='D'||l1=='F')&&\
    (l2=='D'||l2=='F')\
    )

    (l1=='A'&&l2=='B')||\
    (l1=='B'&&l2=='C')||\
    (l1=='D'&&l2=='F')||\
    (l1=='B'&&l2=='A')||\
    (l1=='C'&&l2=='B')||\
    (l1=='F'&&l2=='D')||

*/
