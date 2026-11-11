#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],c=255;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];}
    long long b=0;
    if(m=1){
        for(int i=1;i<=n;i++){b=max(b,a[i])}
        return b;}
    else if(m=2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n){
                c=c&a[i]&a[j];
                b=max(b,c);}}
        return b;}
    else if(m=n){
        for(int i=1;i<=m;i++){
            c=c&a[i];}
        return c;}
    return 0;

}
