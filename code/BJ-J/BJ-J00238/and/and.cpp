#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
const int pow_2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int a[maxn],n,m,sum[maxn],ans=0;
bool tb=true,tc=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1)tb=false;
        if(a[i]>=4)tc=false;
    }
    sum[1]=a[1];
    for(int i=2;i<=n;i++)sum[i-1] & a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n]<<'\n';
    }else if(m==n){
        cout<<sum[n]<<'\n';
    }else if(n<=20){
        for(int i=1;i<=(1<<(n+1));i++){
            int cnt=0,tmp=i,x[31],ans1=0;
            for(int j=30;j>=0;j--){
                if(tmp>=pow_2[j]){
                    x[cnt]=j;
                    cnt++;
                    tmp-=pow_2[j];
                }
                if(tmp==0)break;
            }
            if(cnt==m){
                ans1=a[x[0]];
                for(int k=1;k<cnt;k++)ans1=ans1 & a[x[k]];
            }
            ans=max(ans,ans1);
        }
        cout<<ans<<'\n';
    }else if(n<=2000){
        if(m==1){
            sort(a+1,a+n+1);
            cout<<a[n]<<'\n';
        }else if(m==n){
            cout<<sum[n]<<'\n';
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j)continue;
                    ans=max(ans,a[i] & a[j]);
                }
            }
            cout<<ans<<'\n';
        }
    }else{
        if(tb){
            ans=a[n];
            for(int i=n-1;i>=n-m+1;i--)ans=ans & a[i];
            cout<<ans<<'\n';
        }else if(tc){
            sort(a+1,a+n+1);
            ans=a[n];
            for(int i=n-1;i>=n-m+1;i--){
                ans=ans & a[i];
            }
            cout<<ans<<'\n';
        }else if(m==n-1){
            sort(a+1,a+n+1);
            ans=a[n];
            for(int i=n-1;i>=2;i--)ans=ans & a[i];
            cout<<ans<<'\n';
        }else{
            sort(a+1,a+n+1);
            cout<<a[n-m+1]<<'\n';
        }
    }
    return 0;
}
