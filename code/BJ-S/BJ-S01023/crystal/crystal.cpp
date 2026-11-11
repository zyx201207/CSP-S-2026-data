#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
int ans;
//大数据有误
void solve1(){

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=(j-i+1)*a[j]+sum[i-1]-sum[j];
            if(tmp<=m) ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<n<<" "<<m<<endl;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(n<=5000){
        solve1();
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long tmp=((i-1)*a[i])-sum[i-1];
        //if(i==313324) cout<<tmp<<" "<<m<<endl;
        //if(i==313325) cout<<tmp<<" "<<m<<endl;
        if(tmp<=m) ans=i;
    }
    cout<<ans;
    return 0;
}
