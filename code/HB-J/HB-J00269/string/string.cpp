#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r){
        if(b[l]==b[r]){
            long long mn=min(a[l],a[r]);
            a[l]-=mn;
            a[r]-=mn;
        }else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                a[r]-=a[r];
            }else{
                ans+=a[l];
                a[r]-=a[l];
                a[l]-=a[l];
            }
        }
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
