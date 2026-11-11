#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[500005],add[500005],maxn=0;
bool flag=true;
void temp(){
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]+a[i];
        add[i]=a[i]*(i-1)-num[i-1];
        if(add[i]>m) cout<<i-1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    if(n>5000){
        temp();
        return 0;
    }
    for(int j=1;j<=n;j++){
        flag=true;
        for(int i=j-1;i<=n;i++) num[i]=0;
        for(int i=j;i<=n;i++){
            num[i]=num[i-1]+a[i];
            add[i]=a[i]*(i-j)-num[i-1];
            if(add[i]>m){
                maxn=max((long long)(i-j),maxn);
                flag=false;
                break;
            }
        }
        if(flag) maxn=max((long long)(n-j),maxn);
    }
    cout<<maxn;
    return 0;
}