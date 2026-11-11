#include<bits/stdc++.h>
using namespace std;
int n,a,maxx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>a;
    for(int i=1;i<n;i++){
        cin>>a;
        maxx=max(maxx,a);
    }
    cout<<maxx;
    return 0;
}