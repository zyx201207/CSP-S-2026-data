#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        a[i]=x+2;
    }
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

