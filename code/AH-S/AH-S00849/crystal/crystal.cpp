#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int lt=1,ans=1;
    long long sum=0;
    for(int i=2;i<=n;i++){
        sum+=(i-lt)*(a[i]-a[i-1]);
        while(sum>m){
            sum-=a[i]-a[lt];
            lt++;
        }
        ans=max(ans,i-lt+1);
    }
    cout<<ans<<endl;
    return 0;
}
