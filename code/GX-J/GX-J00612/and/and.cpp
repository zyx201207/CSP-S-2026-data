#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
bool check(int a){
    bool jiancha = 1;
    while(a>0){
        int x = a%2;
        jiancha=(jiancha&&x);
        a/=2;
    }
    return jiancha;
}
bool cmp(int a, int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int sum=a[1], maxn=a[1];
    for(int i = 2; i <= n; i++) {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        sum&=a[i];
    }
    bool flag=1;
    for(int i = 1; i <= n; i++){
        flag=(flag&&check(a[i]));
    }
    if(m==1) cout<<maxn;
    else if(m==n) cout<<sum;
    else if(flag){
        sort(a+1,a+n+1,cmp);
        int ans = a[1];
        for(int i = 2; i <= m; i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(check(n-1)){
        if(n==2){
            cout<<0;
        }else{
            int ans = a[n];
            for(int i = n-1; i > n-m; i--){
                ans&=a[i];
            }
            cout<<ans;
        }
    }
    else cout<<1;
    return 0;
}
