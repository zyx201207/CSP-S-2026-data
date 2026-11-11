#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],ans;
bool check(int x){
    for(int i=x;i<=n;i++){
        long long cha=a[i]*x-(b[i]-b[i-x]);
        if(cha<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    int l=0,r=n;
    while(l<=r){
        int mid=(l+n)/2;
        if(check(mid)){
            ans=mid;
            l++;
        }
        else{
            r--;
        }
    }
    printf("%d",ans);
    return 0;
}

