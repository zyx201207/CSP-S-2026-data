#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    long long n,m,a[10000],sum,maxs=0,x=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        x=0;
        sum=1;
        for(int j=0;j<=i;j++){
            x+=a[i]-a[j];
            if(x>m)
                break;
            sum+=1;
        }
        if(a[i]==a[i+1]) sum+=1;
        if(sum>maxs) maxs==sum;
    }
    cout<<maxs<<endl;
    return 0;
}