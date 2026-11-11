#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long x[220022],two[220022];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
        if(i==1) ans=x[i];
        else ans&=x[i];
        if(i>1) two[i-1]=x[i-1]&x[i];
    }
    sort(x+1,x+n+1);
    sort(two+1,two+n);
    if(m==1) cout<<x[n];
    else if(m==n) cout<<ans;
    else if(m==2) cout<<two[n-1];
    else{
            long long maxx=-1111;
            for(long long j=1;j<=n-m+1;j++){
                long long num=x[j];
                for(long long k=j+1;k<=m+j-1;k++){
                    num&=x[k];
                }
                maxx=max(maxx,num);
            }
            cout<<maxx;
    }
    return 0;
}
