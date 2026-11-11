#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
    }
    long long k=0,l=1,r=n;
    long long ans=0;
    while(k<sum/2){
        long long m=min(a[l],a[r]);
        k+=m;
        if(c[l]!=c[r]) ans+=m;
        a[l]-=m;
        a[r]-=m;
        if(a[l]<=0) l++;
        if(a[r]<=0) r--;
    }
    cout << ans;
    return 0;
}
