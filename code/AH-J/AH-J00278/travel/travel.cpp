#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        string e=b.substr(0,2),f=d.substr(0,2);
        if(e==f){
            cout<<"1";
            if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'||'D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E'){
                cout<<"1";
                if(abs(b[2]-d[2])==1){
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}
