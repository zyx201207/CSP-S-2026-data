#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,res=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++){
        int loc=0,vl=2147483647;
        for(int i=1;i<=n;i++){
            if(a[i]<vl) {
                vl=a[i];
                loc=i;
            }
        }
        res=vl;
        res&=a[loc-1];
        for(int i=loc+1;i<=n;i++){
            a[i-2]=a[i];
        }
    }
    cout<<res;
    return 0;
}
