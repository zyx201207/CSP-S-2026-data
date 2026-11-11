#include<bits/stdc++.h>
using namespace std;
long long n,L=0,ans=0;
long long a[114514191];
char c[114514191];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    for(long long i=1;i<=n;i++){
        if(a[i]==a[n-i+1]&&c[i]==c[n-i+1])continue;
        if(a[i]>a[n-i+1]){
            if(c[i]==c[n-i+1]){
                if(c[n-i]!=c[n-i+1]){
                    ans+=a[i]-a[n-i+1];
                    a[n-1]-=a[i]-a[n-i+1];
                    a[n-i+1]=a[i];
                }
                break;
            }
            ans+=a[n-i+1];
            long long m=a[n-i+1];
            c[n-i+1]=c[i];
            a[n-i+1]=a[i];
            a[n-i]-=a[i]-m;
            if(c[n-i]!=a[i])ans+=a[i]-m;
        }
        else if(a[i]<a[n-i+1]){
            if(c[i]==c[n-i+1]){
                if(c[i+1]!=c[i]){
                    ans+=a[n-i+1]-a[i];
                    a[i+1]-=a[n-i+1]-a[i];
                    a[i]=a[n-i+1];
                }
                break;
            }
            ans+=a[i];
            long long n=a[i];
            c[i]=c[n-i+1];
            a[i]=a[n-i+1];
            a[i+1]-=a[n-i+1]-n;
            if(c[i+1]!=a[i])ans+=a[n-i+1]-n;
        }
        else{
            ans+=a[n-i+1];
            c[n-i+1]=c[i];
        }
    }
    cout<<ans;
    return 0;
}
