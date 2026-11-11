#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    int n,m,a[1000005];
    cin>>n>>m;
    if(m>n)return 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q=a[1]|a[2];
    cout<<q;
    return 0;
}
