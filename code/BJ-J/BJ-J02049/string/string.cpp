#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n;
    while(l<=r){
        long long sum=0;
        long long ll=l,rr=r;
        if(a[l]>a[r]){
            sum=a[r];
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r]){
            sum=a[l];
            l++;
            r--;
        }else{
            sum=a[l];
            a[r]-=a[l];
            l++;
        }
        if(c[ll]!=c[rr]){
            ans+=sum;
        }
    }
    cout<<ans;
    return 0;
}
