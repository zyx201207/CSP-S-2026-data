#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        a[s]++;
    }for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
