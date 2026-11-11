#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char czs1,czg1,czz1,czs2,czg2,czz2,k;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>czs1>>czg1>>czz1;
    cin>>c2;
    cin>>czs2>>czg2>>czz2;
    if(c1==c2){
        cout<<"1";
        a=((czs1-'0')*10+(czg1-'0'));
        b=((czs2-'0')*10+(czg2-'0'));
        if(a==b){
            cout<<"1";
            if(czz1=='A'||czz1=='B'||czz1=='C') c=1;
            else if(czz1=='D'||czz1=='F') c=2;
            if(czz2=='A'||czz2=='B'||czz2=='C') d=1;
            else if(czz2=='D'||czz2=='F') d=2;
            if(c==d){
                cout<<"1";
              //  if(abs(czz1-czz2)==1){
              //      cout<<"1";
              //  }
                if(c==1&&abs(czz1-czz2)==1){
                    cout<<"1";
                }
                else if(c==2&&abs(czz1-czz2)==2){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
}
