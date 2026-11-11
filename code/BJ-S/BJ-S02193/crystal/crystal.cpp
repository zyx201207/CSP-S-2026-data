#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int flag=1;
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        if(i>2&&b[i]!=b[i-1]){
            flag=0;
            }
    } 

    if(flag==1){
        long long x=b[2];
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            cnt=cnt+i*x;
            if(cnt>m){
                break;
            }
            ans++;
        }
        cout << ans;
        return 0;
    }

    long long ans=0;
    for(long long i=1;i<=n;i++){
        for(long long i=1;i<=n;i++){
            b[i]=a[i+1]-a[i];
        } 
        long long cnt=0;
        long long c=1;
        for(long long j=i;j<=n;j++){
            if(cnt+b[j]>m)break;
            cnt+=b[j];
            b[j+1]+=b[j];
            c++;
        }
        ans=max(ans,c);
    }
    cout << ans;
    return 0;
}