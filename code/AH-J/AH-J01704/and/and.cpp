#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[210001],c1,c2,m,n;
bool p(long long q,long long w){return q>w;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,p);c1=a[1];
    for(int i=2;i<=m;i++) c1&=a[i];
    c2=a[2];
    for(int i=2;i<=m;i++) c2&=a[i];
    cout<<max(c1,c2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
