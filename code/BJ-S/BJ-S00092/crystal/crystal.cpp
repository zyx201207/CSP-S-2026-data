#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum,maxq,q;
const int N=5e5+10;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int s=j;s<=i;s++){
                sum+=a[i]-a[s];
            }
            if(sum<m){
                q=i-j;
            }
            maxq=max(q,maxq);
        }
    }
    cout<<maxq;
    fclose(stdin);
    fclose(stdout);
   
    return 0;
}
