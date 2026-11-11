#include<bits/stdc++.h>
using namespace std;
int n;
int a1,a2;
char c1,c2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)cout<<0;
    else{
        cin>>a1>>c1;
        cin>>a2>>c2;
        if(c1==c2)cout<<0;
        else cout<<min(a1,a2);
    }
    return 0;
}

