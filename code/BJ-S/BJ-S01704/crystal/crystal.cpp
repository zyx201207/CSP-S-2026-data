#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long mm;
    for(int i=n;i>=1;i--){
        mm=m;
        int j=i;
        while(mm>=0){
            j--;
            if(j>0){
                mm-=(a[i]-a[j]);
            }
            else{
                break;
            }
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}