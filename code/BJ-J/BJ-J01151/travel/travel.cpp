#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,b1,b2,d1,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>b>>c>>d;
    b1[0]=b[0];
    b1[1]=b[1];
    d1[0]=d[0];
    d1[1]=d[1];
    b2[0]=b[2];
    d2[0]=d[2];

   if(a==c){
    cout<<1;
    if(b1==d1){
        cout<<1;
        /*if(b2==d2)
            cout<<1;*/
            if(b2[0]>='D'&&d2[0]>='D'){
                cout<<"11";
                return 0;
            }
            if(b2[0]<'D'&&d2[0]<'D'){
                    cout<<1;
                if(int(b2[0])-int(d2[0])==1||int(b2[0])-int(d2[0])==-1){
                    cout<<1;
                    return 0;
                }
                cout<<0;
                return 0;
            }

        cout<<"00";
        return 0;
    }
    cout<<"000";
    return 0;
   }
   cout<<"0000";
    return 0;


}
