#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
long long n,m,a[555553],b[555553],c[555553];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long ans=-1;
    for(long long i=1;i<n;i++)b[i]=a[i+1]-a[i];
    c[0]=0;
    for(long long i=1;i<n;i++)c[i]=c[i-1]+b[i];
    unsigned long long tmp=0;long long j=1;
    for(long long i=1;i<n;i++){
        for(j;j<n;j++){
            tmp+=(j-i+1)*b[j];
            if(tmp>m){
                ans=max(ans,j-i+1);
                tmp-=(j-i+1)*b[j];j-=1;
                break;
            }
        }if(j>=n)j-=1;
        tmp-=(c[j]-c[i-1]);j+=1;
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}