#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld ",a+i);
    sort(a+1,a+1+n);
    int l=1;
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=1ll*(a[i]-a[i-1])*(i-l);
        while(l<=i&&sum>m)sum-=a[i]-a[l++];
        bool flag=0;
        while(i<n&&a[i]==a[i+1]){
            flag=1;
            i++;
        }
        ans=max(ans,i-l+1);
        if(flag)i--;
    }
    printf("%d",ans);
    return 0;
}