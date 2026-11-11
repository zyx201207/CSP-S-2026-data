#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n,a[500010],cnt;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int p[n];
    for(int i=0;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    for(int i=n;i>=0;i--){
        if((p[i]+m)%i==0){
            cnt=i;
            break;
        }
    }
cout<<cnt;
    return 0;
}
