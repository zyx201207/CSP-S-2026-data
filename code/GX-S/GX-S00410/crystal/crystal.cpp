#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum,maxx;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=n;i>=1;i--){
            sum=0;
        for(long long j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                if(maxx<i-j-1){
                    maxx=i-j-1;
                }
                break;
            }else if(sum==m){
                if(maxx<i-j){
                    maxx=i-j;
                }
                break;
            }
        }
         if(sum<m){
            maxx=max(maxx,i-1);
         }
    }
    cout<<maxx+1;
    return 0;
}
