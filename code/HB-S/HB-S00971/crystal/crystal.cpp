#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1000005],u=0;
long long a[1000005],l=0,o,k=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,n+s+1);
    s[0]=s[1];
    for(long long i=1;i<=n;i++){
        a[i]=(s[i]-s[i-1])*(i-1)+a[i-1];
        /*
        if(a[i]>m && u==0){
            u=1;
            l=i;
            break;
        }
        */
    }
    /*
    long long x=(m-a[l]);
    for(long long i=1;i<=n;i++){
        long long p=1,q=1;
        for(int j=i+1;j<=n;j++){
            if(s[j]!=s[i]){
                p=j-1;
                break;
            }
        }
        for(int j=o+1;j<=n;j++){
            if(s[o]!=s[j]){
                q=j-1;
                break;
            }
        }
        while(o<=n){
            x+=((p-i+1)*(s[l]-s[i]));
            if(x<0 || (x-(o-p)*(s[q]-s[o])<0)) break;
            x-=((o-p)*(s[q]-s[o]));
            o+=(q-o);
        }

        k=max(k,o-i-1);
    }
    cout<<k;
    */
    for(int i=n;i>=1;i--){
        if(a[i]<=m){
            cout<<i;
            break;
        }
    }
    return 0;
}
