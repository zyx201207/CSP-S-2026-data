#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
//    ios::sync_whitout_stdio(false);
   // cin.tie(0);
   int n;
   int a,b;
   char as,bs;
   cin>>n;
    if(n==1){
        cout<<0;
    }else{
        cout<<min(a,b);
    }
    return 0;
}
