#include <bits/stdc++.h>

using namespace std;

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fastio();

    auto f1 = freopen("travel.in","r",stdin);
    auto f2 = freopen("travel.out","w",stdout);

    int train1,train2;
    string seat1,seat2;
    cin>>train1>>seat1>>train2>>seat2;
    if(train1==train2){
        cout<<"1";
        if(seat1.substr(0,2)==seat2.substr(0,2)){
            cout<<"1";
            char c1=seat1[2],c2=seat2[2];
            if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D')){
                cout<<"1";
                if(abs(c1-c2)==1||(c1>='D'&&c2>='D')){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    cout<<endl;
    return 0;
}