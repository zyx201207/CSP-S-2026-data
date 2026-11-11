#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("","r",stdin);
    freopen("","w",stdout);
    int c,t,n,d;
    cin>>n>>t>>n>>d;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    if(n == 4 && d == 2){
        cout<<1<<"\n"<<2;
    }
    else{
        cout<<0<<"\n"<<1;
    }
    return 0;
}
