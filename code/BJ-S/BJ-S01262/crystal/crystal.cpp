#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],b[maxn],c[maxn],num[maxn];
long long n,m,ans;
bool cmp(long long x,long long y){
    return x<y;
}
void ad(long long l,long long r){
    c[r]-=a[r]-a[l];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=1;
    num[1]=1;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        num[i]=num[i-1]+1;
        c[i]=c[i-1]+b[i]*num[i-1];
        while(c[i]>m){
            ad(l,i);
            l++;
            num[i]--;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,num[i]);
    }
    cout<<ans;
    return 0;
}
