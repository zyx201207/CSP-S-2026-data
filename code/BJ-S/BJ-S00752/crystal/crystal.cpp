#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans=0,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        a[i-1]=a[i]-a[i-1];
    }
    cnt=m;
    for(int i=1;i<n;i++){
        long long z=1;
        for(int j=i;j<=n;j++){
            cnt-=(j-i+1)*a[j];
            if(cnt<0){
                break;
            }
            z++;
        }
        ans=max(ans,z);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}