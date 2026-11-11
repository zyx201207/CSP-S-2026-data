#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int b2,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }

    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }

    if(b[2]=='A'){
        if(d[2]=='B'||d[2]=='C'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
    }else if(b[2]=='B'){
        if(d[2]=='A'||d[2]=='C'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
    }else if(b[2]=='C'){
        if(d[2]=='A'||d[2]=='B'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
    }else if(b[2]=='D'){
        if(d[2]=='F'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
    }else if(b[2]=='F'){
        if(d[2]=='D'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
    }

    if(b[2]=='A'&&d[2]=='B'){
        cout<<"1";
    }else if(d[2]=='A'&&b[2]=='B'){
        cout<<"1";
    }else if(d[2]=='C'&&b[2]=='B'){
        cout<<"1";
    }else if(b[2]=='C'&&d[2]=='B'){
        cout<<"1";
    }else if(d[2]=='D'&&b[2]=='F'){
        cout<<"1";
    }else if(b[2]=='D'&&d[2]=='F'){
        cout<<"1";
    }else cout<<0;
    return 0;
}
