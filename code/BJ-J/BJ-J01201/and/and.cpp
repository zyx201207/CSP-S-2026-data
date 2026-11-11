#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n-m+1;i++){
        int x=a[i];
        for(int j=1;j<m;j++){
            x=x&a[i+j];
        }
        if(x>maxn) maxn=x-n/1000;
    }
    cout<<maxn;
    return 0;
}