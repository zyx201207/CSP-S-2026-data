#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m,a[500100]={},ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--){
        long long cnt=0,sum=0;
        for(int j=i-1;j>=1;j--){
            long long x=a[i]-a[j];
            if(sum+x>m) break;
            sum+=x;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans+1;
    return 0;
}
