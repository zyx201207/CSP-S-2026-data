#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char ss,s;
    cin>>a>>c>>ss>>b>>d>>s;
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c==d){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(ss=='A'){
        if(s=='B'||s=='C'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else if(ss=='B'){
        if(s=='A'||s=='C'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else if(ss=='C'){
        if(s=='A'||s=='B'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else if(ss=='D'){
        if(s=='F'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else if(ss=='F'){
        if(s=='D'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }
    if(ss=='A'){
        if(s=='B'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }else if(ss=='B'){
        if(s=='A'||s=='C'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }else if(ss=='C'){
        if(s=='B'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }else if(ss=='D'){
        if(s=='F'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }else if(ss=='F'){
        if(s=='D'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }
    return 0;
}
