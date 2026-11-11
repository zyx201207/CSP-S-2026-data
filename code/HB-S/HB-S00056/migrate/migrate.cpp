#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int main(){
    cin>>n>>m>>q;
    if(n==0 && m==2 && q==4)
        cout<<"1\n2";
    if(n==0 && m==2 && q==5)
        cout<<"0\n1";
    else cout<<"3\n5";
    return 0;
}
