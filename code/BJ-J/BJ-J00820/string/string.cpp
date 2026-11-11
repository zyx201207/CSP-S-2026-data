#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];

    }
    long long r=1,l=n;
    while(r<=l){
        if(b[r]!=b[l]){
            if(a[r]>a[l]){
                a[r]-=a[l];
                ans+=a[l];
                l--;
            }else if(a[r]<a[l]){
                a[l]-=a[r];

                ans+=a[r];
                r++;
            }else if(a[r]==a[l]){
                ans+=a[r];
                l--;
                r++;


            }
        }
        else if(b[r]==b[l]){
            if(a[r]>a[l]){
                a[r]-=a[l];
                l--;
            }else if(a[r]<a[l]){
                a[l]-=a[r];
                r++;
            }else if(a[r]==a[l]){
                l--;
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}
