#include<bits/stdc++.h>
using namespace std;

string a,a1,b,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b){//两张车票对应的座位是否在同一节车厢;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a1[0]==b1[0]&&a1[1]==b1[1]){//两张车票对应的座位是否在同一节车厢的同一排;
        if(a==b){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if(a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C'||a1[2]=='F'&&b1[2]=='D'||a1[2]=='D'&&b1[2]=='F'){//两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
            if(a1[2]!=b1[2]){
                cout<<1;
            }
            else {
                cout<<0;
            }
        }
        else {
            cout<<0;
        }
    }
    else{
            cout<<0<<0;
        }
    if(a==b&&a1[0]==b1[0]&&a1[1]==b1[1]&&a1[2]!=b1[2]&&(a1[2]==b1[2]+1||a1[2]+1==b1[2]||a1[2]=='D'&&b1[2]=='F'||a1[2]=='F'&&b1[2]=='D')){//两张车票对应的座位是否相邻。
        if(a1[2]=='D'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='D'){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
