#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m,sum=0;
    cin>>n>>m;
    for(long long i=0;i<n;++i){
        long long x;
        cin>>x;
        a.push_back(x);
        sum+=x;
    }
    if(n>10000){
        long long dp=1,s=0;
        while(m>0){
            m-=dp;
            dp+=1;
            s++;
        }
        cout<<s;
        return 0;
    }
    sum/=m;
    long long i=0,cnt=1;
    while(sum-a[i]>=0){
        ++i;
    }
    for(long long j=i-1;j<n;++j){
        if(a[j]==a[j+1]){
            cnt++;
        }
    }
    for(long long j=i-1;j>=0;--j){
        if(a[i-1]-a[j]<=m&&a[i-1]-a[j]!=0){
            m=m-a[i-1]+a[j];
            a[j]=a[i-1];
        }
        if(m<=0){
            break;
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}
