#include<bits/stdc++.h>
using namespace std;
int r,x;
char a[5],b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>a;
    cin>>x>>b;
    if(r!=x){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    if(r==x) {
        cout<<1;
        if(a[0]==b[0]){
            if(a[1]==a[1]){
                cout<<1;
                if(a[2]>=65&&a[2]<=67){
                    if(b[2]>=65&&b[2]<=67){
                        cout<<1;
                        if(abs(a[2]-b[2])==1||abs(a[2]-b[2])==0) cout<<1;
                        else cout<<0;
                    }
                    if(b[2]>67){
                        cout<<0;
                        cout<<0;
                    }
                }
                if(a[2]==68||a[2]==69){
                    if(b[2]==68||b[2]==69){
                        cout<<11;
                    }
                    if(b[2]<68){
                        cout<<0;
                        cout<<0;
                    }
                }
            }
            if(a[1]!=b[1]){
                cout<<0;
                cout<<0;
                cout<<0;
            }
        }
    }
    return 0;
}
