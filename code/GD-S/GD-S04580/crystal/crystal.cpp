#include <bits/stdc++.h>
using namespace std;
long long m,a[500005],sum,ans,v;
int n;
int main()
{   
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
    	sum=0;
        for (int j=1;j<i;j++){
            sum+=(a[i]-a[j]);
        }
        if (sum>m){
        	long long z=m;
            for (int j=i-2;j>=1;j--){
                if (z-(a[i-1]-a[j])>=0){
                    z-=(a[i-1]-a[j]);
                    ans++;
                }
            }
        }
        v=max(ans,v);
        ans=0;
    }
    cout<<v+1;
}
