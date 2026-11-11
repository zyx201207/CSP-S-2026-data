#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    unsigned long long ans=0;
    cin>>n;
    int a[200005];
    char c[200005];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long la=a[1],ra=a[n];
    for(int i=1;i<=n;i++){
        if(l>=r){
            break;
        }
        if(c[l]!=c[r]){
            ans+=min(la,ra);
            if(la==ra){
                l++;
                r--;
                la=a[l];
                ra=a[r];
            }else if(la>ra){
                la-=ra;
                r--;
                ra=a[r];
            }else{
                ra-=la;
                l++;
                la=a[l];
            }
        }else{
            if(la==ra){
                l++;
                r--;
                la=a[l];
                ra=a[r];
            }else if(la>ra){
                la-=ra;
                r--;
                ra=a[r];
            }else{
                ra-=la;
                l++;
                la=a[l];
            }
        }
    }
    cout<<ans;
    return 0;
}