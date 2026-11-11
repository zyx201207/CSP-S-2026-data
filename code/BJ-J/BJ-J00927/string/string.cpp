#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,r,l=1;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    r=n;
    while(l<=r){
        if(a[l]>=a[r]){
            if(c[l]!=c[r]) sum+=a[r];
            a[l]-=a[r];
            r--;
        }
        else{
            if(c[l]!=c[r]) sum+=a[l];
            a[r]-=a[l];
            l++;
        }
    }
    cout<<sum;
    return 0;
}
