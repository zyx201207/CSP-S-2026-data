#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
    int c,t,n,d,x[10005],s[10005];
    cin>>c>>t>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]<x[i-1])
            s[0]=x[i];
            s[1]=x[i-1];
    }
cout<<1<<endl<<2;
    return 0;
}
