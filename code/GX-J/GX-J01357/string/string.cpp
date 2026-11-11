#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,a[200009],l,r,dy,lf,rf,s;//dy is duoyu's mean.
char c[200009],dyc,lc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==lc){
            a[i-1]+=a[i];
            i--;
            n--;
        }
        lc=c[i];
    }
    r=n-1;
    for(;l<r;l++,r--){
        if(c[l]==c[r]){
            int jj=min(a[l],a[r]);
            if(a[l]>a[r]){
                a[l]-=jj;
                a[r]=0;
                l--;
            }
            else if(a[l]<a[r]){
                a[r]-=jj;
                a[l]=0;
                r++;
            }
        }
        else{
            int jj=min(a[l],a[r]);
            s+=jj;
            if(a[l]>a[r]){
                a[l]-=jj;
                a[r]=0;
                l--;
            }
            else if(a[l]<a[r]){
                a[r]-=jj;
                a[l]=0;
                r++;
            }
        }

    }
    cout<<s;
    return 0;
}
