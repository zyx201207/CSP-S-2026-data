#include<bits/stdc++.h>
using namespace std;
//#define int long long
long long n,l,r,q,w;
int a[200100];
int b[200100];
char c[100100];
char d[100100];
long long ans=0,lo=0,js=0,t=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        lo+=a[i];
    }
    w=(lo+1)/2;
    for(int i=1;i<=n;i++){
        js+=a[i];
        if(js>w&&js-a[i]+1<w){
            if(w==lo/2){
                t++;
                b[t]=w-js+a[i];
                d[t]=c[i];
                t++;
                b[t]=js-w;
                d[t]=c[i];
            }else{
                t++;
                b[t]=w-js+a[i]-1;
                d[t]=c[i];
                t++;
                b[t]=1;
                d[t]=c[i];
                t++;
                b[t]=js-w;
                d[t]=c[i];
            }
            continue;
        }
        if(js>w&&js-a[i]+1==w){
            if(w==lo/2){
                t++;
                b[t]=w-js+a[i];
                d[t]=c[i];
                t++;
                b[t]=js-w;
                d[t]=c[i];
            }else{
                t++;
                b[t]=1;
                d[t]=c[i];
                t++;
                b[t]=js-w;
                d[t]=c[i];
            }
            continue;
        }
        if(js==w&&js-a[i]+1<w){
            if(w==lo/2){
                t++;
                b[t]=a[i];
                d[t]=c[i];
            }else{
                t++;
                b[t]=w-js+a[i]-1;
                d[t]=c[i];
                t++;
                b[t]=1;
                d[t]=c[i];
            }
            continue;
        }
        t++;
        b[t]=a[i];
        d[t]=c[i];
    }
    l=1;
    r=t;
    while(l<=r){
        if(a[l]>a[r]){
            a[l]-=a[r];
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            r--;
        }else if(a[l]<a[r]){
            a[r]-=a[l];
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            l++;
        }else{
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
