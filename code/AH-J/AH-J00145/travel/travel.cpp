#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3) {
        cout<<"1";
        if(c1[1]==c3[1]&&c1[2]==c3[2]){
            cout<<"1";
            if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C')){
                 cout<<"1";
                 if(abs((int)c2[2]-(int)c4[2])==1)
                      cout<<"1";
                 else 
                      cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
