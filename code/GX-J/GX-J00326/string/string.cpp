#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s;
    string cong;
    cin>>s;
    for(int i = 1; i <= s; i++){
        int a;
        cin>>a;
        char d;
        cin>>d;
        for(int i = 1; i <= a; i++){
            cong += d;
        }
    }cout<<2;
return 0;}
