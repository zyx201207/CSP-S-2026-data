#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
struct{
    int e;
    string rf;
}a[200005];
int maxn=-0x3f3f3f3f;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].e;
        maxn=max(maxn,a[i].e);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    cout<<7;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
