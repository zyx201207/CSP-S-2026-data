#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn];
long long tong[maxn];
int n;
long long m;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >>n >>m;
    for(int i=1; i<=n; ++i){
        cin >>a[i];
        tong[a[i]]++;
    }
    sort(a+1, a+n+1);
    long long diff=a[2]-a[1];
    long long mind=diff;
    long long pos=2;
    bool flag1=1;
    for(int i=3; i<=n; ++i){
        if(a[i]-a[i-1]!=diff){
            flag1=0;
            break;
        }
        if(a[i]-a[i-1]<=diff){
            mind=a[i]-a[i-1];
            pos=i;
        }
    }
    bool flag2=1;
    for(int i=2; i<=n; ++i){
        if(a[i]==a[i-1]){
            flag2=0;
            break;
        }
    }
    if(flag1){
        long long cnt=0;
        int k=1;
        while(m>=0&&k<=n){
            cnt++;
            m-=k*diff;
            k++;
        }
        cout <<cnt;
    }
    else
    {
        long long ans=1;
        for(int i=1; i<=n; ++i){
            long long cnt=0;
            long long M=m;
            long long k=i-1;
            while(M>=0&&k>=0){
                cnt++;
                M-=(a[i]-a[k]);
                k--;
            }
            ans=max(ans, cnt);
        }
        cout <<ans;
    }
    return 0;
}