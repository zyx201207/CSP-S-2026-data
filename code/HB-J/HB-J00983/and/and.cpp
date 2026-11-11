#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=0,p=0;
    int a=0,q[200001],o=0,c=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>c;
        s=max(c,s);
    }
    cout<<s;
    return 0;
}
