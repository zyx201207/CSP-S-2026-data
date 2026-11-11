#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005],l=0,cnt=0;
    char c[200005],d[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)d[l++]=c[i];
    }for(int i=0;i<=l/2;i++){
        if(d[i]!=d[l-i])cnt++;
    }cout<<cnt;
    return 0;
}