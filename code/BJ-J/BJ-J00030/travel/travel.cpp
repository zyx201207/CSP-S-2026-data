#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,aid;
    string b,bid;
    cin>>a>>aid>>b>>bid;
    int p = (aid[0]-'0'*10)+aid[1]-'0';
    int q = (bid[0]-'0'*10)+bid[1]-'0';
    int p1 = (a[0]-'0'*10)+a[1]-'0';
    int q1 = (b[0]-'0'*10)+b[1]-'0';
    if(p1!=q1){
        cout<<"0000";
    }else{
        cout<<1;
        char sa = aid[2];
        char sb = bid[2];
        if(p==q){
            cout<<"1";
            if(sa>='D'&&sb>='D'||sa<='C'&&sb<='C'){
                cout<<1;
                if(abs(sa-sb)==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }
    return 0;
}
