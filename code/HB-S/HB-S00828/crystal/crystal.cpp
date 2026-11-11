#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt,f[N],k,x=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    while(m){
        if((x*(a[k+1]-a[k]))<=m){
            m-=x*(a[k+1]-a[k]);
            a[k]=a[k+1];
            cnt+=x;
            k++;
            x++;
        }else break;
    }while(a[k+1]==a[k]){
        cnt++;
        k++;
    }
    cout<<cnt;
    return 0;
}
