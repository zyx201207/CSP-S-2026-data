#include<bits/stdc++.h>
using namespace std;
const int da=500010;
long long a[da],sum[da],n,m;
bool cmp(const long long& x,const long long& y){
    return x<y;
}
int er_fen(int x,int i){
    int l=0,r=i,ans=0;
    while(l<r){
        int mid=(l+r)/2;
        int su=sum[i-1]-sum[i-mid-1];
        if(mid*x-su>m){
            r=mid;
        }
        else{
            ans=(l+r)/2;
            l=mid+1;
        }
    }
    return ans+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        long long sum=0,cnt1=1,x=a[i],cnt=1;
        cnt1=er_fen(x,i);
        /*for(int j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                break;
            }
            cnt++;
        }
        if(cnt!=cnt1){
            cout<<"false"<<endl;
        }*/
        maxn=max(maxn,cnt1);
    }
    cout<<maxn<<"\n";
    return 0;
}
