#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int n,m;
int sum[150];
void ans(){
    long long maxn=0;
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=n;i++){
        int cnt=0;
        while(b[i]){
            sum[++cnt]+=b[i]%2;
            b[i]/=2;
        }
    }
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=n;i++){
        int cnt=0;
        while(b[i]){
            sum[++cnt]-=b[i]%2;
            b[i]/=2;
        }
        long long p=1;
        long long cot=0;
        for(int i=1;i<=62;i++){
            cot+=sum[i]/(n-1)*p;
            p*=2;
        }
        maxn=max(maxn,cot);
        b[i]=a[i];
        cnt=0;
        while(b[i]){
            sum[++cnt]+=b[i]%2;
            b[i]/=2;
        }
    }
    cout<<maxn;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(m==1){
            int maxn=0;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }else if(m==2){
        int maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return  0;
    }else if(m==n){
        for(int i=1;i<=n;i++){
            a[1]=a[1]&a[i];
        }
        cout<<a[1];
        return 0;
    }else if(m==n-1){
        ans();
        return 0;
    }
    else{
        sort(a+1,a+1+n);
        for(int i=n;i>=n-m+1;i--){
            a[n]&=a[i];
        }
        cout<<a[n];
    }
    return 0;
}
