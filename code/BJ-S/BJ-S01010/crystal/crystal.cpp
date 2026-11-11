#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum=1,maxv=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long q=0;
    for(int i=2;i<=n;i++){
        sum=1;
        if(a[i]==a[i+1])continue;
        for(int j=i-1;j>0;j--){
            q=a[i]-a[j];
            m-=q;
            if(m<0)break;
            a[j]=a[i];
            sum++;
        }
        maxv=max(maxv,sum);
    }
    cout<<maxv;
    return 0;
}
