#include<bits/stdc++.h>
using namespace std;
long long a,b,e,f;
char c,d;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>e>>f>>d;
    if(a!=e){
        cout<<"0000\n";
        return 0;
    }
    if(b!=f){
        cout<<"1000\n";
        return 0;
    }
    if((c=='A'&&d=='D')||(c=='A'&&d=='F')||(c=='B'&&d=='D')||(c=='B'&&d=='F')||(c=='C'&&d=='D')||(c=='C'&&d=='F')){
        cout<<"1100\n";
        return 0;
    }
    if((c=='A'&&d=='C')||(c=='C'&&d=='A')){
        cout<<"1110\n";
        return 0;
    }
    cout<<"1111\n";

    return 0;
}
