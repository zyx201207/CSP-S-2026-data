#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[20000]={},maxn=0,c;
    cin >>n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<i+m-1;j++){
            c = (a[j] & a[j+1]);
        }
        if(maxn < c) maxn = c;
    }
    cout << maxn;
    return 0;
}
