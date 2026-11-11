#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s1[500005],s2[500005],maxx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s1[1]=0;
    s2[1]=0;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s1[i]=s1[i-1]+a[i]-a[i-1];
        s2[i]=s2[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    for(long long i=2;i<=n;i++){
        for(long long j=1;j<=i-1;j++){
            cout<<j<<"-->"<<i<<":"<<s2[i]-s2[j-1]-(j-1)*(s1[i]-s1[j-1])<<endl;
            if(s2[i]-s2[j-1]-(j-1)*(s1[i]-s1[j-1])<=m){
                maxx=max(maxx,i-j+1);
                break;
            }
        }
    }
    cout<<maxx;
    return 0;
}
