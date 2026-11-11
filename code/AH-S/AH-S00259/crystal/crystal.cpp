#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,i,j;
    cin>>n>>m;
    long long a[n],ans[m];
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ans[0]=1;
    for(i=1;i<n;i++){
        long long s=0,x=0;
        for(j=x;j<i;j++){
            s+=a[i]-a[j];
            if(s>m){
                s=0;
                x++;
                j=x;
            }
        }
        ans[i]=i-x+1;
    }
    sort(ans,ans+n);
    cout<<ans[n-1];
    return 0;
}
