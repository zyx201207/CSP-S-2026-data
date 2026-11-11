#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[114514191],b[114514191];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        long long x,y=0;
        cin>>x;
        a[i]=x;
        long long E[500005],cnt=0;
        while(x!=0){
            E[++cnt]=x%2;
            x=x/2;
        }
        for(long long j=cnt;j>=1;j--){
            if(E[j]==1)E[j]=0;
            else E[j]=1;
        }
        for(long long h=1;h<=cnt;h++)y+=E[h]*pow(2,h-1);
        b[i]=y;
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    long long maa=0,maxn,mab=-1,bi;
    for(long long i=1;i<=n;i++){
        if(b[i]>mab){
            mab=b[i];
            maxn=i;
        }
    }
    for(long long i=1;i<=n;i++){
        if(a[i]>maa){
            maa=a[i];
            maxn=i;
            bi=b[i];
        }
        else if(a[i]==maa&&b[i]>b[maxn]){
            maa=a[i];
            maxn=i;
            bi=b[i];
        }
    }
    ans=maa;
    sort(b+1,b+n+1);
    bool f=false;
    for(long long i=1;i<=m;i++){
        if(b[i]==bi)f=true;
        ans-=b[i];
    }
    if(f)ans=ans+bi-b[m+1];
    cout<<ans;
    return 0;
}
