#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    m=2;
    vector <int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxn=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            maxn=max(a[i]&a[j],maxn);
        }
    }
    cout<<maxn;
    return 0;
}