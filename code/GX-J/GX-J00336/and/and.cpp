#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int maxn;
    int p;
    int a[n-1]={};
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int b=1;b<=m;b++)
        maxn=n[j] & n[j+1];
    for(int j=0;j<n;j++){
         for(int b=2;b<=m;b++)
            p=n[j] & n[j+1];
         if(max(maxn,p)) maxn=p;
    }
    cout << maxn;
    return 0;
}
