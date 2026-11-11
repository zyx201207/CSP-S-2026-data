#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout)
    char sa[5]={},sb[5]={},a[3]={},b[3]={};
    for(int i=1;i<=2;i++){
        cin>>a[i];
    }
    for(int i=1;i<=3;i++){
        cin>>sa[i];
    }
    for(int i=1;i<=2;i++){
        cin>>b[i];
    }
    for(int i=1;i<=3;i++){
        cin>>sb[i];
    }
    if(a[1]==b[1]&&a[2]==b[2]){
        cout<<1;
        if(sa[1]==sb[1]&&sa[2]==sb[2]){
            cout<<1;
            if('A'<=sa[3]<='C'&&'A'<=sb[3]<='C'||'D'<=sa[3]<='F'&&'D'<=sa[3]<='F'){
                cout<<1;
                if(sa[3]+1==sb[3]||sa[3]-1==sb[3]){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<00;
            }
        }else{
            cout<<0;
            if('A'<=sa[3]<='C'&&'A'<=sb[3]<='C'||'D'<=sa[3]<='F'&&'D'<=sa[3]<='F'){
                cout<<10;
            }else{
                cout<<00;
            }
        }
    }else{
        cout<<0;
        if('A'<=sa[3]<='C'&&'A'<=sb[3]<='C'||'D'<=sa[3]<='F'&&'D'<=sa[3]<='F'){
                cout<<010;
            }else{
                cout<<000;
            }
        }
    }
    return 0;
}