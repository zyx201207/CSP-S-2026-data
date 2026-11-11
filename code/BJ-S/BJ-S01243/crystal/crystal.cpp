#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=0;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i+1]==a[i]){
            continue;
        }
        long long mm=m;
        long long s=1;
        for(int j=i-1;j>=0;j--){
            if(mm-(a[i]-a[j])>=0){
                mm=mm-(a[i]-a[j]);
                s++;
            }
            else{
                break;
            }
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}
