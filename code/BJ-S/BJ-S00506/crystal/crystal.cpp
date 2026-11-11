#include <bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long a[500005];
long long c[205];
long long b[205];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    int flg=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>100) flg=0;
        if(a[i]<-100) flg=0;
    }
    sort(a+1,a+n+1);
    if(n==1){
        cout<<1;
        return 0;
    }
    if(m==0){
        long long lst=a[1],cnt=1,ans=0;
        for(int i=2;i<=n;i++){
            if(a[i]==lst){
                cnt++;
            }else ans=max(ans,cnt),cnt=1;
            lst=a[i];
        }
        ans=max(ans,cnt);
        cout<<ans;
        return 0;
    }
    if(flg==1){
        int pt=0;
        for(int i=1;i<=n;i++){
            a[i]+=100;
            c[a[i]]++;
            if(i==1) b[++pt]=a[i];
            else if(a[i]!=a[i-1]) b[++pt]=a[i];
        }
        long long ans=0;
        for(int i=1;i<=pt;i++){
            long long cnt=c[b[i]],sum=0;
            for(int j=i-1;j>=1;j--){
                sum+=(b[i]-b[j])*c[b[j]];
                if(sum>m){
                    int z=b[i]-b[j];
                    sum-=z*c[b[j]];
                    cnt+=(m-sum)/z;
                    break;
                }
                cnt+=c[b[j]];
                //cout<<cnt<<" ";
            }
            //cout<<cnt<<"\n";
            ans=max(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    int flag=1,gc=a[2]-a[1];
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=gc){
            flag=0;
        }
    }
    if(flag==1){
        long long sum=0,cnt=0;
        for(int i=n;i>=1;i--){
            sum+=(a[n]-a[i]);
            if(sum>m) break;
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long cnt=1,sum=0;
        for(int j=i-1;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum>m) break;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
