#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int cnt=4,b1,d1,b2,d2;
    cin>>a>>b>>c>>d;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        b1=0;
    }
    else{
        b1=1;
    }
    if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
        d1=0;
    }
    else{
        d1=1;
    }
    b2=b[2]-64;
    d2=d[2]-64;
    if(a[0]==c[0]&&a[1]==c[1]){
        cout<<1;
        cnt-=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            cnt-=1;
            if(b1==d1){
                cout<<1;
                cnt-=1;
                if(b2==4&&d2==6){
                    cout<<1;
                    cnt--;
                }
                if(b2==6&&d2==4){
                    cout<<1;
                    cnt--;
                }
                if(b2==1&&d2==2){
                    cout<<1;
                    cnt--;
                }
                if(b2==2&&d2==1){
                    cout<<1;
                    cnt--;
                }
                if(b2==2&&d2==3){
                    cout<<1;
                    cnt--;
                }
                if(b2==3&&d2==2){
                    cout<<1;
                    cnt--;
                }
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        cout<<0;
    }
    return 0;
}
