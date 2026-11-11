#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int j=1,n,a[N];
long long x,w;
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        w+=a[i];
    }
    while(x<w/2){
        x+=a[j];
        j++;
    }
    int l=1,r=n;
    long long ans=w/2;
    while(l<=j&&r>=j){
        if(s[l]==s[r]){
            ans-=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }else if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }else{
            l++;
            r--;
        }
        if(l==r){
            ans-=a[l]/2;
        }
    }
    cout<<ans;
    return 0;
}
