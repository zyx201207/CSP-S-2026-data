#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int wei1,lei1,wei2,lei2;
    char zhuo1,zhuo2;
    cin>>wei1>>lei1>>zhuo1>>wei2>>lei2>>zhuo2;
    if(wei1!=wei2) cout<<"0000";
    else if(lei1!=lei2) cout<<"1000";
    else if(!(zhuo1<='C'&&zhuo2<='C'||zhuo1>'C'&&zhuo2>'C')) cout<<"1100";
    else if(zhuo1>'C'&&zhuo2>'C'||zhuo1+1==zhuo2) cout<<"1111";
    else cout<<"1110";
    return 0;
}
