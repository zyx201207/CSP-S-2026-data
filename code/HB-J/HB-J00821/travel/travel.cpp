#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        string b1=b.substr(0,2);
        string d1=d.substr(0,2);
        if(b1==d1){
            cout<<1;
            char b2=b[2];
            char d2=d[2];
            if(('A'<=b2&&'C'>=b2&&'A'<=d2&&'C'>=d2)||((b2=='D'&&d2=='F')||(b2=='F'&&d2=='D'))){
                cout<<1;
                if((b2=='D'&&d2=='F')||(b2=='F'&&d2=='D')||(b2=='A'&&d2=='B')||(b2=='B'&&d2=='A')||(b2=='B'&&d2=='C')||(b2=='C'&&d2=='B')){
                    cout<<1;
                }else{
                    cout<<"0"<<endl;
                    }
                }else{
                    cout<<"00"<<endl;
                    return 0;
                }

        }else{
            cout<<"000"<<endl;
            return 0;
        }
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    return 0;
}
