#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int out[4]={0,0,0,0};
    int a,b;
    string c,d;
    cin>>a;
    cin>>c;
    cin>>b;
    cin>>d;
    int cb=0,ca=0,da=0,db=0;
    if(c[0]==1){
        ca+=10;
    }
    ca+=c[1]-'0';
    if(d[0]==1){
        da+=10;
    }
    da+=d[1]-'0';
    if(c[2]=='A'){
        cb=1;
    }else if(c[2]=='B'){
        cb=2;
    }else if(c[2]=='C'){
        cb=3;
    }else if(c[2]=='D'){
        cb=5;
    }else{
        cb=6;
    }
    if(d[2]=='A'){
        db=1;
    }else if(d[2]=='B'){
        db=2;
    }else if(d[2]=='C'){
        db=3;
    }else if(d[2]=='D'){
        db=5;
    }else{
        db=6;
    }
    if(a==b){
        out[0]=1;
        if(ca==da){
            out[1]=1;
            if(cb==1&&db==2||cb==1&&db==3||cb==2&&db==1||cb==2&&db==3||cb==3&&db==1||cb==3&&db==2||cb==5&&db==6||cb==6&&db==5){
                out[2]=1;
                if(cb==1&&db==2||cb==2&&db==3||cb==2&&db==1||db==2&&cb==3||cb==5&&db==6||cb==6&&db==5){
                    out[3]=1;
                    for(int i=0;i<4;i++){
                        cout<<out[i];
                    }
                }else{
                    for(int i=0;i<4;i++){
                        cout<<out[i];
                    }
                }
            }else{
                for(int i=0;i<4;i++){
                    cout<<out[i];
                }
            }
        }else{
            for(int i=0;i<4;i++){
                cout<<out[i];
            }
        }
    }else{
        for(int i=0;i<4;i++){
            cout<<out[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
