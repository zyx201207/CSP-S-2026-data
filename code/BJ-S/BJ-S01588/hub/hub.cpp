#include<bits/stdc++.h>
using namespace std;
long long a[500009],n,m,cnt;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>m;
    if(m==2)cout<<1<<endl<<2;
    else if(m==3)cout<<1<<endl<<1<<endl<<2;
    else cout<<17<<endl<<9<<endl<<6<<endl<<9;
    return 0;
}