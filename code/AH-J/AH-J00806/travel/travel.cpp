#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char c,d;
bool x1,x2,x3,x4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>c>>a2>>b2>>d;
    if(a1==a2){
        x1=1;
    }else{
        x1=0;
    }
    if(b1==b2&&x1==1){
        x2=1;
        if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){
            x3=1;
            if(abs(int(c)-int(d))==1){
                x4=1;
            }
        }else if((c=='D'||c=='F')&&(d=='D'||c=='F')){
            x3=1;
            if(abs(int(c)-int(d))==1){
                x4=1;
            }
        }else{
            x3=0;
        }
    }else{
        x2=0;
    }
    cout<<x1<<x2<<x3<<x4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

