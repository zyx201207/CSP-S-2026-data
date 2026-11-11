#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],h,maxx=-1000000000000,k=-1000000000000;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(a[1]-a[2]==a[2]-a[3]&&n>=3){
        long long sum=1,d=a[2]-a[1];
        while(sum*(sum-1)/2<=m/d&&sum<=n)sum++;
        cout<<sum-1;;
        return 0;
    }
    for(int i=1;i<=n;i++){
        h+=maxx-a[i];
    }
    if(h<=m){
        cout<<n;;
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long c[500005];
        for(int j=1;j<=n;j++){
            c[j]=abs(a[i]-a[j]);
        }
        sort(c+1,c+n+1);
        long long sum=0,ave=0;
        for(int j=1;j<=n;j++){
            sum+=c[j];
            if(sum<=m)ave++;
            else break;
        }
        k=max(k,ave);
    }
    cout<<k;;
    return 0;
}
