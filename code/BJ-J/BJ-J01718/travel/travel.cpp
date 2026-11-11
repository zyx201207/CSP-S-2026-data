#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool is1=false,is2=false,is3=false,is4=false;
    if(a==c){
        is1=true;
        if(b[0]==d[0]&&b[1]==d[1]){
            is2=true;
            if(b[2]=='A'){
                if(d[2]=='B'){
                    is3=true;
                    is4=true;
                }else if(d[2]=='C'){
                    is3=true;
                    is4=false;
                }else{
                    is3=false;
                    is4=false;
                }
            }else if(b[2]=='B'){
                if(d[2]=='A'){
                    is3=true;
                    is4=true;
                }else if(d[2]=='C'){
                    is3=true;
                    is4=true;
                }else{
                    is3=false;
                    is4=false;
                }
            }else if(b[2]=='C'){
                if(d[2]=='B'){
                    is3=true;
                    is4=true;
                }else if(d[2]=='A'){
                    is3=true;
                    is4=false;
                }else{
                    is3=false;
                    is4=false;
                }
            }else if(b[2]=='D'){
                if(d[2]=='F'){
                    is3=true;
                    is4=true;
                }else{
                    is3=false;
                    is4=false;
                }
            }else if(b[2]=='F'){
                if(d[2]=='D'){
                    is3=true;
                    is4=true;
                }else{
                    is3=false;
                    is4=false;
                }
            }
        }else{
            is2=false;
            is3=false;
            is4=false;
        }
    }else if(a!=c){
        is1=false;
        is2=false;
        is3=false;
        is4=false;
    }
    cout<<is1<<is2<<is3<<is4;
    return 0;
}
