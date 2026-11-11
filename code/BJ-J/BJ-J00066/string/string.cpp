#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i]>>b[i];

    long long l=1,r=n,ans=0;
    while(l<r){
        if(a[l]>=a[r]){
            long long s=a[r];
            a[l]-=a[r];
            a[r]=0;
            if(b[l]!=b[r])
                ans+=s;
            r--;
        }else{
            long long s=a[l];
            a[r]-=a[l];
            a[l]=0;
            if(b[l]!=b[r])
                ans+=s;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
