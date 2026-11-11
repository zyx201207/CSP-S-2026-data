#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[10005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b=0;
    for(int j=0;j<n;j++){
        for(int s=0;s<m;s++){
            int c=(a[j]&a[s+1]);
            b=max(b,c);
        }
    }
    cout<<b;

    return 0;
}

