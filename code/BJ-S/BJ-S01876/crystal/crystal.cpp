#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    long long m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            long long tar=a[i]*(i-mid+1);
            long long cur=tar-(s[i]-s[mid-1]);
            if(cur<=m){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//Arsenal was and still is my love.
//North London Forever.
