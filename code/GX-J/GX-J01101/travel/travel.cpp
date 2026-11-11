#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,a,b;
    cin >> c >> s >> a >>b;
    int x=0,y=0;
    char l,r;
    l=s[2];
    r=b[2];
    x+=s[0]-'0';
    y+=b[0]-'0';
    x*=10;
    y*=10;
    x+=s[1]-'0';
    y+=b[1]-'0';
    int p;
    if(c==a){
        cout<<1;
            if(x==y){
            cout<<1;
        }
        else{
            cout<<0;
            p=1;
        }
        int o=0;
        if((l<='C' && r<='C') || (l>'C' && r>'C') ){
            if(p!=1){
                cout<<1;
                o=1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }
        if(o==1){
            while(true){
                if(l=='A' && r=='B'){
                    cout<<1;
                    break;
                }
                else{

                    cout<<0;
                    break;
                }
                if(l=='B' && (r=='A' || r=='C') ){

                    cout<<1;
                    break;
                }
                else{

                    cout<<0;
                    break;
                }
                if(l=='C' && r=='B'){
                    cout<<1;
                break;
                }
                else{

                    cout<<0;
                    break;
                }
                if(l=='D' && r=='E'){

                    cout<<1;
                                break;
                }
                else{

                    cout<<0;
                    break;
                }
                if(l=='E' && r=='D'){

                    cout<<1;
                    break;
                }
                else{

                    cout<<0;
                    break;
                }
            }
        }
        else {
            cout<<0;
        }


    }
    else{
        cout<<0000;
    }


 return 0;
}
