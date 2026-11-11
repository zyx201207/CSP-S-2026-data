#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b[10005],maxx=-9999999;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i];
        maxx=max(maxx,b[i]);
    }
    cout<<maxx;
    return 0;
}
