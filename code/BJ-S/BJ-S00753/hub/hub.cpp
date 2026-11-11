#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long q,p;
int main(){
    freopen("hug.in","r",stdin);
    freopen("hug.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        for(long long i=1;i<=x-1;i++){
            cin>>q>>p;
        }
        cout<<y-1<<endl;
    }
    return 0;
}
