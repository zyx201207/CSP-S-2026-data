#include <bits/stdc++.h>
using namespace std;

inline long long fastread(){
    long long x=0, f=1;
    char c=getchar_unlocked();
    while(c<'0' || c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar_unlocked();
    }
    while(c>='0' && c<='9'){
        x=x*10+c-48;
        c=getchar_unlocked();
    }
    return x*f;
}

long long a[500001], num[500001], m, n, ans=0;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n=fastread();
    m=fastread();
    num[1]=0;
    for(long long i=1;i<=n;i++){
        a[i]=fastread();
    }
    sort(a+1, a+1+n);
    for(long long i=n-1;i>=1;i--){
        num[i]=num[i+1]+a[n]-a[i];
    }
    long long right=n;
    for(long long left=n-1;left>=1;left--){
        while(num[left]-num[right]-(right-left)*(a[n]-a[right])>m && left<right-1){
            right--;
        }
        ans=max(ans, right-left+1);
    }
    cout<<ans<<endl;
    return 0;
}
