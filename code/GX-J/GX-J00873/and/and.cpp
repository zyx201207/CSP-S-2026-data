#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ull n,m,o=0;
    vector<ull> T;
    cin>>n>>m;
    for(ull i=0;i<n;i++){
        ull a;
        cin>>a;
        T.push_back(a);
    }
    sort(T.begin(),T.end(),greater<ull>());
    o=T[0];
//    cout<<o<<"\n";
    for(const ull& b : T){
//    cout<<o<<"^"<<b<<"="<<(o&b)<<"\n";
    if(o&b!=0){
        o=o&b;
        m--;
    }
    if(m<=0) break;
    }
    cout<<o;
    return 0;
}
