#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long c=0,sum=1;
        for(int j=i-1,k=i+1;c+min(a[i]-a[j],a[k]-a[i])<=m;){
            if(a[i]-a[j]>a[k]-a[i]&&k<=n){
                c+=a[k]-a[i];
                k++;
                sum++;
            }
            else if(a[i]-a[j]<=a[k]-a[i]&&j>=1){
                c+=a[i]-a[j];
                j--;
                sum++;
            }
            else{
                break;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
