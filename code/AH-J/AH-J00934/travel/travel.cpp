#include<bits/stdc++.h>
using namespace std;
char a,b;
long long h,l,k,j;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>h>>l>>a>>k>>j>>b;
    long long o=0,p=0,e=0;
    if(h==k){
    cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(l==j){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(a=='A'||a=='B'||a=='C'){
        if(b=='A'||b=='B'||b=='C'){
            cout<<"1";
            if(abs(int(a-b))==1){
                cout<<"1";
                return 0;
            }else{
                cout<<"0";
                return 0;
            }
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(a=='D'||a=='F'){
        if(b=='D'||b=='F'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        cout<<"00";
        return 0;
    }
    return 0;
}
