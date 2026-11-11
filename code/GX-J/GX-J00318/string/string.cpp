#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[200010];
    short c[200010];
    int n;cin>>n;
    long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
        char x;cin>>x;
        c[i]=x-'a';
    }
    int l=1,r=n;
    long lsum=0,rsum=0;
    long mid=(ans>>1);
    long sum=0;
    while(lsum<=mid&&rsum<=mid){
        if(a[l]>a[r]){
            if(c[l]!=c[r])sum+=a[r];
            lsum+=a[r];rsum+=a[r];
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r])sum+=a[l];
            lsum+=a[l];rsum+=a[l];
            a[r]-=a[l];
            l++;
        }
        else{
            if(c[l]!=c[r])sum+=a[l];
            lsum+=a[l];rsum+=a[r];
            l++;r--;
        }
    }
    cout<<sum;
    return 0;
}
