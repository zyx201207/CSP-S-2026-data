#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],h[200010],t[200010],sum;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],h[i]=h[i-1]+a[i];
    for(int i=n;i>=1;i--) t[i]=t[i+1]+a[i];
    long long p1=1,p2=n;
    while(p1<p2){
        while(t[p2]<=h[p1]){
            if(c[p1]!=c[p2]) sum+=t[p2]-max(t[p2+1],h[p1-1]);
            p2--;
        }
        if(c[p1]!=c[p2]) sum+=h[p1]-max(t[p2+1],h[p1-1]);
        p1++;
    }
    cout<<sum;
    return 0;
}