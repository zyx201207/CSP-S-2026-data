#include<bits/stdc++.h>
using namespace std;
long long ans,cnt,lj,rj;
long long a[200005];
string c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
    lj+=a[1];
    rj+=a[n];
    cnt=(cnt+1)/2;
    long long l=1,r=n;
    while(lj<cnt&&rj<cnt){
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=min(a[l],a[r]);
                a[l]-=a[r];
                r--;
                rj+=a[r];
            }else if(a[l]<a[r]){
                ans+=min(a[r],a[l]);
                a[r]-=a[l];
                l++;
                lj+=a[l];
            }else{
                ans+=a[l];
                l++;
                r--;
                lj+=a[l];
                rj+=a[r];
            }
        }else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
                rj+=a[r];
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
                lj+=a[l];
            }else{
                l++;
                r--;
                lj+=a[l];
                rj+=a[r];
            }
        }
    }
    if(c[l]!=c[r]&&l-r>=-1){
        ans+=min(a[l],a[r]);
    }else if(l-r<=-2){
        if(l>=cnt){
            while(l!=r){
                if(c[r]==c[l]){
                    r--;
                }else{
                    ans+=a[r];
                    r--;
                }
            }
        }else{
            while(l!=r){
                if(c[r]==c[l]){
                    l++;
                }else{
                    ans+=a[l];
                    l++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
