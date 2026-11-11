#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[200010];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
        a[n]=-1;
    for(int i=0;i<n;i++){
        if(a[i+1]!=a[i]);
        cout<<i+1<<" ";
    }
    return 0;
}
