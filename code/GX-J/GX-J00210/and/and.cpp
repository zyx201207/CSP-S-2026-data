#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[10005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b=0;
    for(int j=0;j<n;j++){
        for(int s=j;s<m;s++){
            int c=(a[s]&a[s+1]);
            b=max(b,c);
        }
    }
    cout<<b;

    return 0;
}
