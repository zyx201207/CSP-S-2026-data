#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    char b,d;
    int e,f;
    int g=0,k=0,q=0;
    cin>>a>>e>>b>>c>>f>>d;
    if(a==c){
        cout<<"1";
        g=1;
    }
    else cout<<0;
    if(e==f&&g==1){
        cout<<"1";
        q=1;
    }
    else {cout<<"0";}

    if(b=='C'&&d=='D'||d=='C'&&b=='D'){
        if(q!=1) cout<<"0";
    }
    else {
        if(q==1){
            cout<<"1";
            k=1;
        }
        else cout<<"0";
    }

    int p=abs(b-d);
    if(p==1){
        if(k==1){
            cout<<"1";
        }
        else cout<<"0";
    }
    else cout<<"0";
    return 0;
}
