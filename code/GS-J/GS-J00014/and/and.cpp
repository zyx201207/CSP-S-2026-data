#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s,p=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int j=(int)log2(a[n]),x=0,o;j>=0;--j){
        x=(1<<j);o=lower_bound(a+p,a+n+1,x)-a;
        for(int i=o;i<=n;i++)a[i]-=x;
        if(n-o+1>=m){
            s+=x;
            p=o;
        }sort(a+p,a+n+1);
    }cout<<s;
    return 0;
}
