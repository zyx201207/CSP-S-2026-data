#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
long long a[N],b[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long cnt,cnt2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            cnt=a[i];
        }else {
        cnt=(cnt&a[i]);
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(i==1){
            cnt2=a[i];
        }else {
        if(i!=n) cnt2=(cnt2&a[i]);
        }
    }
    b[1]=a[1];
    long long j=2;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]) b[j++]=a[i];
    }

    if(m==1){
        cout<<b[1];
        return 0;
    }else if(m==2){
        cout<<b[2];
        return 0;
    }else if(m==n){
        cout<<cnt;
        return 0;
    }else if(m==(n-1)) {
        cout<<cnt2;
        return 0;
    }
    long long ans;
    ans=b[1];
    for(int i=2;i<=m;i++){
        ans=(ans&b[i]);
    }
    cout<<ans;
    return 0;
}
