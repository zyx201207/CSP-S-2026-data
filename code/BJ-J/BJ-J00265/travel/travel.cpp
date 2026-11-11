#include<bits/stdc++.h>
using namespace std;
struct S{
    int a;
    char b;
    char c;
    char d;
}s,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s.a>>s.b>>s.c>>s.d>>x.a>>x.b>>x.c>>x.d;
    if(s.a==x.a){
        cout<<1;
        if(s.b==x.b&&s.c==x.c){
            cout<<1;
            if((s.d=='A'||s.d=='B'||s.d=='C')&&(x.d=='D'||x.d=='F')||(x.d=='A'||x.d=='B'||x.d=='C')&&(s.d=='D'||s.d=='F')){
                cout<<"00";
            }else{
                cout<<1;
                if(s.d=='B'||x.d=='B'||s.d=='D'||s.d=='F'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
