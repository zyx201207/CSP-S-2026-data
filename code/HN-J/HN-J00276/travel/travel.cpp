#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int cnt=0;
    if(a1==b1)cout<<1;
    else cout<<'0000'<<'\n';
    for(char x:a2){
        for(char y:b2){
            if(x==y)cnt++;

            continue;
        }
    }

    return 0;
}
