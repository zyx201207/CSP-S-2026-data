#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,t;
    cin>>n>>t;
    int a[n],pai[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            if(a[j]==a[i]) pai[a[i]]++;
        }
    }
    for(int i=0;i<t;i++) cout<<pai[i]<<' ';
    return 0;
}
