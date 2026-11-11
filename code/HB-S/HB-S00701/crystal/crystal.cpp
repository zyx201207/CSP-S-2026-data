#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool flag1=1,flag2=1;
    cin>>n>>m;
//  n=N-10,m=1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
//        a[i]=i*(10000000000000000LL/i+n%i+i+m%n);
        if(a[i]==0) a[i]=7891911;
        if(a[i]!=a[i-1]&&i!=1){
            flag1=0;
        }
        if(i!=1&&i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            flag2=0;
        }
    }
    //cout<<flag2<<'\n';
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[n]-a[i];
    }
    if(flag1){
        cout<<n;
        return 0;
    }
    if(flag2){
        int d=a[2]-a[1];
        m/=d;
        long long l=1,r=1e9;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*(mid+1)/2==m){
                cout<<min(1LL*n,mid+1);
                return 0;
            }else if(mid*(mid+1)/2>m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<min(1LL*n,l);
        return 0;
    }
    if(sum<=m){
        cout<<n;
        return 0;
    }
    for(int i=n;i>=1;i--){
        //cout<<a[i]<<'\n';
        int cnt=0;
        long long o=m;
        for(int j=i;j>=1;j--){
            if(o>=a[i]-a[j]){
                o-=a[i]-a[j];
                cnt++;
            }else{
                break;
            }
        }
        //cout<<i<<' '<<a[i]<<' '<<cnt<<'\n';
        ans=max(ans,cnt);
        if(cnt==i){
            break;
        }
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

10 2
1 1 1 1 1 1 1 1 1 1

6 10
1 3 5 7 9 11
*/
