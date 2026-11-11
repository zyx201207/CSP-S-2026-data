#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n,m;
    int mx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mx=max(mx,a[i]&a[j]);
        }
    }
    cout<<mx;
    return 0;
}
