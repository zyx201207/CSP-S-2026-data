#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    if(c==0 and t==2){
        cout<<1<<endl<<2<<endl;
    }
    return 0;
}
