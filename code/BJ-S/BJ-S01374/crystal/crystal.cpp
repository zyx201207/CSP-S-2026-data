#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,ans;
long long a[500050],f[500050];
bool check(long long mid,long long d){
    long long sum=d*mid*(mid-1);
    return sum<=m;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<=5000){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        long long cnt=1;
        for(int i=1;i<=n;i++){
            long long x=a[i];
            if(x==a[i+1])cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
                x=a[i];
            }
        }
        for(int i=1;i<n;i++){
            long long num=m,cnt=1;
            for(int j=i-1;j>=1;j--){
                f[j]=a[i]-a[j];
                if(num>=f[j]){
                    num-=f[j];
                    cnt++;
                }else break;
            }
            for(int j=i+1;j<=m;j++){
                if(a[j]==a[i])cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<"\n";
        return 0;
    }else{
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        long long d=a[2]-a[1];
        long long l=1,r=n,mid;
        while(l<=r){
            mid=r-(r-l)/2;
            if(check(mid,d)){
                l=mid+1;
                ans=max(ans,mid);
            }else r=mid-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}