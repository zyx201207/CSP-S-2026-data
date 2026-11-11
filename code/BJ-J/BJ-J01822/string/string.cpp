#include<bits/stdc++.h>
using namespace std;
    long long n,a[200005];
    //long long sum=0,t=0;
    long long ans=0;
    char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //sum+=a[i];
        //sum+=(a[i]/2);
        //t+=a[i]%2;
    }
    //sum+=(t/2);
    long long l=1,r=n;
    while(l<=r){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }
        else {
            if(c[l]!=c[r])ans+=a[l];
            l++;
            r--;
        }
    }
    cout<<ans;
return 0;}
