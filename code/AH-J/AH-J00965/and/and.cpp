#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int d=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>d) d=a[i];
    }
    cout<<d;

 return 0;
}
