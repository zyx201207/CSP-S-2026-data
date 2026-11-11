#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long a[200005];
    char c[200005];
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ans+=a[i];
    }
    int r=n;
    long long cnt=0;
    for(int l=1;l<r;){
        if(c[r]==c[l]){
            a[r]-=min(a[r],a[l]);
            a[l]-=min(a[r],a[l]);
        }
        else{
            cnt+=min(a[r],a[l]);
            long long sum=min(a[r],a[l]);
            a[r]-=sum;
            a[l]-=sum;

        }
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<cnt;
    return 0;
}
