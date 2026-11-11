#include <bits/stdc++.h>
using namespace std;
const int MAXL=300000;
int a[MAXL];
bool cmp(int a,int b){
    if(a>b) return 1;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
    if(m=n){
        int cnt=(a[0]|a[1]);
        for(int i=1;i<=n-1;i++){
            cnt+=(cnt|a[i+1]);
            cout<<cnt;
        }

    }
    else{
        sort(a[1],a[n],cmp);
        cout<<a[0];
    }
    return 0;
}



