#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],a1[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[1];
    long long maxn=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
        a1[i]=a[i]&a[i-1];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    maxn=0;
    long long maxn2=0;
    for(int i=1;i<=n;i++){
        maxn=max(a1[i],maxn);
    }
    for(int i=1;i<=n&&m==2;i++){
        for(int j=i+1;j<=n;j++){
            maxn2=max(a[i]&a[j],maxn2);
        }
    }
    cout<<max(maxn,maxn2);
    return 0;
}
