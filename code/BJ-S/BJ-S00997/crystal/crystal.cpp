#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],ans=1,b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    //solvea();
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            b[i]=a[i];
        }
        long long cnt=1,x=m;
        for(int j=i-1;j>=1;j--){
            if(b[i]==b[j]){
                cnt++;
                continue;
            }
            int d=b[i]-b[j];
            if(d<0) d=-d;
            if(x>=d){
                x-=d;
                ++cnt;
                b[j]=b[i];
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
