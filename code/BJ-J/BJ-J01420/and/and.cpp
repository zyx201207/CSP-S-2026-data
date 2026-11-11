#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int n,m,a[200005]={0},maxn=-100000000,b,ans=pow(2,30)-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxn){
            maxn=a[i];
        }
    }
    sort(a+1,a+1+n);
    for(int i=n;i>n-m;i--)ans=ans&a[i];
    cout<<ans;
    return 0;
}
