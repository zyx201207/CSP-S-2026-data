#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[100000],best;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            x=a[i]&a[j];
            y=max(x,y);
        }
        best=max(best,y);
    }
    cout<<best;
    freopen("and.out","w",stdout);
    freopen("and.in","w",stdout);
    return 0;
}