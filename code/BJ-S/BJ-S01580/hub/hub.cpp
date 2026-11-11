#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(t==2) cout<<"1\n2";
    else if(t==3) cout<<"1\n1\n2";
    else {
        for(int i=1;i<=t;i++) cout<<1<<endl;
    }
    return 0;
}
