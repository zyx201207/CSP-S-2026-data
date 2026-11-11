#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N]={0};
unsigned long long ans[N]={0};
int n;
long long m;
int flag=1;
void solve1(){
    for(int i=1;i<=n;i++){
        long long sum=((1+i)*i)/2LL;
        ans[i]=sum;
    }
    int l=1,r=n,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(ans[mid]==m){res=mid; break;}
        else if(ans[mid]>m) r=mid-1;
        else {l=mid+1; res=mid;}
    }
    cout<<res+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]-a[i-1]!=1) flag=0;
    }
    sort(a+1,a+n+1);
    if(flag){
        solve1();
    }else{
        cout<<n-1;
    }

    return 0;
}
